#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<int> rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();
    int base = 256;          
    int mod = 101;         

    int patHash = 0;        
    int txtHash = 0;        
    int h = 1;           

    for (int i = 0; i < m - 1; i++)
        h = (h * base) % mod;

    for (int i = 0; i < m; i++) {
        patHash = (base * patHash + pattern[i]) % mod;
        txtHash = (base * txtHash + text[i]) % mod;
    }

    vector<int> positions;

    for (int i = 0; i <= n - m; i++) {
        if (patHash == txtHash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) positions.push_back(i);
        }

        if (i < n - m) {
            txtHash = (base * (txtHash - text[i] * h) + text[i + m]) % mod;
            if (txtHash < 0) txtHash += mod; 
        }
    }
+
    return positions;
}

int main() {
    string text = "PrabhjeetSeengh";
    string pattern = "ee";

    vector<int> result = rabinKarp(text, pattern);

    cout << "Pattern found at positions: ";
    for (int pos : result) cout << pos << " ";
    cout << endl;

    return 0;
}