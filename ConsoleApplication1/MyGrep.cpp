#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // Asetetaan paikallinen asetukset suomen kielelle
    setlocale(LC_ALL, "fi_FI");

    // Jos komentoriviparametreja ei ole annettu
    if (argc == 1) {
        // Käyttäjä syöttää lauseen ja hakusanan
        string sana, lause;

        cout << "Syötä merkkijono josta etsiä hakutulosta: ";
        getline(cin, lause);
        cout << endl << "Syötä hakusana: ";
        getline(cin, sana);

        // Etsitään hakusanaa lauseesta
        size_t index = lause.find(sana);
        if (index != string::npos) {
            cout << "Hakusana löytyi lauseesta kohdasta " << index << endl;
        }
        else {
            cout << "Hakusanaa ei löytynyt lauseesta" << endl;
        }
    }
    // Jos komentoriviparametreja on 3 tai 4
    else if (argc == 3 || argc == 4) {
        bool l_option = false, o_option = false;
        string hakusana, tiedostonimi;

        // Jos optioita on annettu
        if (argc == 4) {
            string optiot = argv[1];
            if (optiot.find('l') != string::npos) l_option = true;
            if (optiot.find('o') != string::npos) o_option = true;
            hakusana = argv[2];
            tiedostonimi = argv[3];
        }
        // Jos optioita ei ole annettu
        else {
            hakusana = argv[1];
            tiedostonimi = argv[2];
        }

        // Avataan tiedosto
        ifstream tiedosto(tiedostonimi);
        if (!tiedosto) {
            cerr << "Virhe: Tiedostoa ei voitu avata!" << endl;
            return 1;
        }

        string rivi;
        int rivinumero = 0;
        int loydetytRivit = 0;

        // Luetaan tiedosto rivi kerrallaan
        while (getline(tiedosto, rivi)) {
            rivinumero++;

            // Jos hakusana löytyy riviltä
            if (rivi.find(hakusana) != string::npos) {
                if (l_option) cout << rivinumero << ": ";
                cout << rivi << endl;
                loydetytRivit++;
            }
        }

        // Jos 'o' optio on annettu, tulostetaan löytyneiden rivien määrä
        if (o_option) {
            cout << "Occurrences of lines containing \"" << hakusana << "\": " << loydetytRivit << endl;
        }

        // Suljetaan tiedosto
        tiedosto.close();
    }
    // Jos komentoriviparametreja on virheellinen määrä
    else {
        cerr << "Virheellinen määrä argumentteja!" << endl;
        return 1;
    }

    return 0;
}
