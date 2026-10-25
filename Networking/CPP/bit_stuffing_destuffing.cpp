#include <iostream>
using namespace std;

string bitStuffing(string data) {
    string stuffed = "";
    int count = 0;

    for (char bit : data) {
        stuffed += bit;

        if (bit == '1') {
            count++;
            if (count == 5) {
                stuffed += '0'; 
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return stuffed;
}

string bitDestuffing(string data) {
    string destuffed = "";
    int count = 0;

    for (int i = 0; i < data.length(); i++) {
        destuffed += data[i];

        if (data[i] == '1') {
            count++;
            if (count == 5) {
                i++;  
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return destuffed;
}

int main() {
    string data;
    cout << "Enter bit stream: ";
    cin >> data;

    string stuffed = bitStuffing(data);
    cout << "Stuffed Data: " << stuffed << endl;
    string destuffed = bitDestuffing(stuffed);
    cout << "De-stuffed Data: " << destuffed << endl;
    return 0;
}

