#pragma once
#include "UI.h"
class Valid
{
public:
    //se valideaza input-ul pentru a fi numar
	int read_nr() {
        int x;
        cin >> x;
        while (!cin)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input\n";
            cout << "Zahl eingeben "; cin >> x;
        }
        return x;
	}
    // se valideaza pentru a fi numar dar dintre numerele disponibile in meniu
    int read_range(int n) {
        int x;
        cin >> x;
        while (!cin || x>n || x<0)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input\n";
            cout << "Zahl eingeben <= als: "<<n<<'\n'; cin >> x;
        }
        return x;
    }
    //se valideaza input-ul pentru a fi string
    string read_string() {
        string arg;
        cin.ignore();
        getline(cin, arg);
        return arg;
    }

};

