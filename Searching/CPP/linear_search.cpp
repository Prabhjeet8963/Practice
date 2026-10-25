/*
Problem: Implement linear search to find key k in an array. 
Count and display the number of comparisons performed. 

Input: - First line: integer n (array size)
Second line: n space-separated integers 
Third line: integer k (key to search)
 
Output: - 
 Line 1: "Found at index i" OR "Not Found"
 Line 2: "Comparisons = c"
 

 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // Input array
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int comparisons = 0;
    int foundIndex = -1;

    // Linear Search
    for (int i = 0; i < n; i++) {
        comparisons++;

        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        cout << "Found at index " << foundIndex << endl;
    } else {
        cout << "No matches" << endl;
    }

    cout << "Comparisons = " << comparisons << endl;

    return 0;
}