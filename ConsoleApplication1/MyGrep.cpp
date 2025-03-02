#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

// Funktio muuntaa merkkijonon pieniksi kirjaimiksi
string toLowerCase(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

int main(int argc, char* argv[]) {
    // Asetetaan paikallinen asetukset suomen kielelle
    setlocale(LC_ALL, "fi_FI");

    // Jos komentoriviparametreja ei ole annettu
    if (argc == 1) {
        string sana, lause;

        // Pyydet‰‰n k‰ytt‰j‰‰ syˆtt‰m‰‰n merkkijono ja hakusana
        cout << "Syˆt‰ merkkijono josta etsi‰ hakutulosta: ";
        getline(cin, lause);
        cout << endl << "Syˆt‰ hakusana: ";
        getline(cin, sana);

        // Muutetaan molemmat pieniksi kirjaimiksi
        string lauseLower = toLowerCase(lause);
        string sanaLower = toLowerCase(sana);

        // Etsit‰‰n hakusanaa annetusta merkkijonosta (pienill‰ kirjaimilla)
        size_t index = lauseLower.find(sanaLower);
        if (index != string::npos) {
            cout << "Hakusana lˆytyi lauseesta kohdasta " << index << endl;
        }
        else {
            cout << "Hakusanaa ei lˆytynyt lauseesta" << endl;
        }
    }
    // Jos komentoriviparametreja on annettu
    else if (argc >= 3) {
        bool l_option = false, o_option = false, i_option = false, r_option = false;
        string hakusana, tiedostonimi;

        int index = 1;
        // Tarkistetaan, onko optioita annettu
        if (argv[1][0] == '-') {
            string optiot = argv[1];
            if (optiot.find('l') != string::npos) l_option = true;
            if (optiot.find('o') != string::npos) o_option = true;
            if (optiot.find('i') != string::npos) i_option = true;
            if (optiot.find('r') != string::npos) r_option = true;
            index++;
        }

        // Tarkistetaan, onko hakusana ja tiedostonimi annettu
        if (argc > index + 1) {
            hakusana = argv[index];
            tiedostonimi = argv[index + 1];
        }
        else {
            cerr << "Virhe: Puuttuu hakusana tai tiedostonimi!" << endl;
            return 1;
        }

        // Avataan tiedosto
        ifstream tiedosto(tiedostonimi);
        if (!tiedosto) {
            cerr << "Virhe: Tiedostoa '" << tiedostonimi << "' ei voitu avata!" << endl;
            return 1;
        }

        // Muutetaan hakusana pieniksi kirjaimiksi, jos 'i' optio on annettu
        if (i_option) {
            hakusana = toLowerCase(hakusana);
        }

        string rivi;
        int rivinumero = 0;
        int loydetytRivit = 0;

        // Luetaan tiedosto rivi kerrallaan
        while (getline(tiedosto, rivi)) {
            rivinumero++;

            // Muutetaan rivi pieniksi kirjaimiksi, jos 'i' optio on annettu
            string vertailtavaRivi = i_option ? toLowerCase(rivi) : rivi;

            // Tarkistetaan, lˆytyykˆ hakusana rivilt‰
            bool loytyi = (vertailtavaRivi.find(hakusana) != string::npos);

            // Tulostetaan rivi, jos hakusana lˆytyy tai ei lˆydy riippuen 'r' optiosta
            if ((r_option && !loytyi) || (!r_option && loytyi)) {
                if (l_option) cout << rivinumero << ": ";
                cout << rivi << endl;
                loydetytRivit++;
            }
        }

        // Tulostetaan lˆytyneiden rivien m‰‰r‰, jos 'o' optio on annettu
        if (o_option) {
            cout << "Rivien m‰‰r‰, jotka "
                << (r_option ? "EIVƒT " : "")
                << "sis‰lt‰v‰t \"" << hakusana << "\": " << loydetytRivit << endl;
        }

        // Suljetaan tiedosto
        tiedosto.close();
    }
    // Jos komentoriviparametreja on virheellinen m‰‰r‰
    else {
        cerr << "Virheellinen m‰‰r‰ argumentteja!" << endl;
        return 1;
    }

    return 0;
}
