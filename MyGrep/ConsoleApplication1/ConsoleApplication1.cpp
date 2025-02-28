#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	// Suomenkielinen merkistö
	setlocale(LC_ALL, "fi_FI");

    //tarkistetaann argumenttien määrä

	// Ohjelma etsii käyttäjän syöttämän hakusanan toisesta käyttäjän syöttämästä merkkijonosta
    string sana;
    string lause;

    // Pyydetään käyttäjältä lause ja hakusana
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


    return 0;
}