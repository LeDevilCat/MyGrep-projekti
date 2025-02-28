#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    // Suomenkielinen merkistö
    setlocale(LC_ALL, "fi_FI");

    if (argc == 1) {
        // Käyttäjä syöttää lauseen ja hakusanan
        string sana, lause;

        cout << "Syötä merkkijono josta etsiä hakutulosta: ";
        getline(cin, lause);
        cout << endl << "Syötä hakusana: ";
        getline(cin, sana);

        // Etsitään hakusana lauseesta
        size_t index = lause.find(sana);
        if (index != string::npos) {
            cout << "Hakusana löytyi lauseesta kohdasta " << index << endl;
        }
        else {
            cout << "Hakusanaa ei löytynyt lauseesta" << endl;
        }
    }

    else if (argc == 3) {
        // VAIHE 2: Luetaan tiedosto ja etsitään hakusanaa**
        string hakusana = argv[1];  // Hakusana tulee komentoriviltä
        string tiedostonimi = argv[2];  // Tiedostonimi tulee komentoriviltä

        ifstream tiedosto(tiedostonimi);  // Avataan tiedosto
        if (!tiedosto) {
            cerr << "Virhe: Tiedostoa ei voitu avata!" << endl;
            return 1;
        }

        string rivi;
        while (getline(tiedosto, rivi)) {  // Luetaan tiedosto rivi kerrallaan
            if (rivi.find(hakusana) != string::npos) {  // Jos hakusana löytyy riviltä
                cout << rivi << endl;  // Tulostetaan rivi
            }
        }

        tiedosto.close();  // Suljetaan tiedosto lopuksi
    }

    else {
        cerr << "Virheellinen määrä argumentteja!" << endl;
        return 1;
    }

    return 0;
}
