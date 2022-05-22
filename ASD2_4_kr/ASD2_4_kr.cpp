#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//funckja liczaca szukany hash
int Hash_wanted(int pn, int base, string wzorzec) {

    if (wzorzec.size() > 0)
        int temporary = wzorzec[0];

    for (size_t i = 0; i < wzorzec.size(); i++) {
        int(wzorzec[i])*base+wzorzec[i+1]
    }
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

        //pn - liczba pierwsza, base- podstawa do wyliczania hash
        int pn = 151, base = 256;
        base %= pn;

        if (wzorzec.size() == 0) {
            if (n-- > 0)
                cout << '\n';
            
        }
        else {

            Hash_wanted(pn, base, wzorzec);
        }


        file.close();
        n--;
    }
}