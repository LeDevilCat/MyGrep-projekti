#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    // Suomenkielinen merkist�
    setlocale(LC_ALL, "fi_FI");

    if (argc == 1) {
        // K�ytt�j� sy�tt�� lauseen ja hakusanan
        string sana, lause;

        cout << "Sy�t� merkkijono josta etsi� hakutulosta: ";
        getline(cin, lause);
        cout << endl << "Sy�t� hakusana: ";
        getline(cin, sana);

        // Etsit��n hakusana lauseesta
        size_t index = lause.find(sana);
        if (index != string::npos) {
            cout << "Hakusana l�ytyi lauseesta kohdasta " << index << endl;
        }
        else {
            cout << "Hakusanaa ei l�ytynyt lauseesta" << endl;
        }
    }

    else if (argc == 3) {
        // VAIHE 2: Luetaan tiedosto ja etsit��n hakusanaa**
        string hakusana = argv[1];  // Hakusana tulee komentorivilt�
        string tiedostonimi = argv[2];  // Tiedostonimi tulee komentorivilt�

        ifstream tiedosto(tiedostonimi);  // Avataan tiedosto
        if (!tiedosto) {
            cerr << "Virhe: Tiedostoa ei voitu avata!" << endl;
            return 1;
        }

        string rivi;
        while (getline(tiedosto, rivi)) {  // Luetaan tiedosto rivi kerrallaan
            if (rivi.find(hakusana) != string::npos) {  // Jos hakusana l�ytyy rivilt�
                cout << rivi << endl;  // Tulostetaan rivi
            }
        }

        tiedosto.close();  // Suljetaan tiedosto lopuksi
    }

    else {
        cerr << "Virheellinen m��r� argumentteja!" << endl;
        return 1;
    }

    return 0;
}
