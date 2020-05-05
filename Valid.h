#pragma once
#include "UI.h"
class Valid
{
public:
	double read_nr() {
        double x;
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

};

