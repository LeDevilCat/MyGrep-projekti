#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
	// Suomenkielinen merkist�
	setlocale(LC_ALL, "fi_FI");

    //tarkistetaann argumenttien m��r�

	// Ohjelma etsii k�ytt�j�n sy�tt�m�n hakusanan toisesta k�ytt�j�n sy�tt�m�st� merkkijonosta
    string sana;
    string lause;

    // Pyydet��n k�ytt�j�lt� lause ja hakusana
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


    return 0;
}