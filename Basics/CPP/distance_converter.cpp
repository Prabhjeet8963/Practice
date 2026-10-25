#include <iostream>
using namespace std;
float kilometers,meters,feet,miles;

int main() { 
    double distance; 
    char unit;
    cout << "Enter the distance: ";
    cin >> distance;
    cout << "Enter the unit (m for miles, k for kilometers, f for feet, t for meters): "; 
    cin >> unit; 
      

    switch (unit) {
        case 'm':
            miles = distance;
            kilometers = distance * 1.60934;
            meters = distance * 1609.34;
            feet = distance * 5280;
            break;
        case 'k':
            miles = distance * 0.621371;
            kilometers = distance;
            meters = distance * 1000;
            feet = distance * 3280.84;
            break;
        case 'f': 
            miles = distance / 5280;
            kilometers = distance / 3280.84;
            meters = distance * 0.3048;
            feet = distance;
            break;
        case 't': 
            miles = distance / 1609.34;
            kilometers = distance / 1000;
            meters = distance;
            feet = distance * 3.28084;
            break;
        default:
            cout << "Invalid unit entered." << endl;
    }

    cout << "Equivalent distances:" << endl;
    cout << "Miles: " << miles << endl;
    cout << "Kilometers: " << kilometers << endl;
    cout << "Meters: " << meters << endl;
    cout << "Feet: " << feet << endl;

 return 0;
}



