#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

//liczy szukany hash
int Hash_wanted(string wzorzec) {

    //pn - liczba pierwsza
    int pn = 151, base = 256;
    base %= pn;
    int temporary = int(wzorzec[0]);

    for (size_t i = 0; i < wzorzec.size() - 1; i++)
        temporary = (temporary * base + int(wzorzec[i + 1])) % pn;

    return temporary;
}

//liczy kolejne hashe
int Hash(int hash, int previous, int next, int  wzorzec_size) {

    int pn = 151, base = 256;
    base %= pn;
    int temporary;
    int power = 1;

    power = 1;
    for (int i = 0; i < wzorzec_size - 1; i++) {
        power *= base;
        power %= pn;
    }

    temporary = hash - ((previous * power) % pn);
    if (temporary < 0)
        temporary += pn;

    return (temporary * base + next) % pn;
}

int main()
{
    // n - liczba przypadkow testowych
    int n;
    cin >> n;

    while (n) {

        //wczytuje nazwe pliku wejsciowego i wzorzec
        string file_name, wzorzec;
        cin >> file_name;
        cin.ignore();
        getline(cin, wzorzec);

        ifstream file;
        file.open(file_name);

        //wczytuje tekst z pliku
        string text, new_text;
        while (getline(file, new_text))
            text += new_text;
        

        if (wzorzec.size() > 0) {

            int hash_wanted;
            hash_wanted = Hash_wanted(wzorzec);
            int wzorzec_size = wzorzec.size();
            string ancillary = text.substr(0, wzorzec_size);
            int hash = Hash_wanted(ancillary);

            for (size_t i = 0; i < text.size() - wzorzec_size + 1; i++) {

                if (i != 0)
                    hash = Hash(hash, int(text[i - 1]), int(text[i + wzorzec_size - 1]), wzorzec_size);

                if (hash == hash_wanted) {

                    bool check = true;
                    //sprawdza czy ciagi znakow sa sobie rowne
                    for (int j = 0; j < wzorzec_size; j++) {
                        if (text[i + j] != wzorzec[j]) {
                            check = false;
                            break;
                        }
                    }

                    if (check)
                        cout << i << ' ';
                }


            }
        }

        
        file.close();
        n--;
        if (n)
            cout << '\n';
    }
}