#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

//funckja liczaca szukany hash
int Hash_wanted(string wzorzec) {

    int pn = 151, base = 256;
    base %= pn;
    long long int temporary = int(wzorzec[0]);

    for (size_t i = 0; i < wzorzec.size() - 1; i++) 
        temporary = (temporary * base + int(wzorzec[i + 1])) % pn;
    
    return temporary;
}

int Hash(int hash, int previous, int next, int  wzorzec_size) {
    
    int pn = 151, base = 256;
    base %= pn;
    long long int temporary;
    long long int power = pow(base, wzorzec_size - 1);

    temporary = hash - ((previous * power % pn) % pn);
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
        cin >> file_name >> wzorzec;

        ifstream file;
        file.open(file_name);

        //wczytuje tekst z pliku
        string text;
        getline(file, text);

        if (wzorzec.size() > 0 || wzorzec.size() > text.size()) {

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
                    for (size_t j = 0; j < wzorzec_size; j++) {
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