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
        cout << "Not Found" << endl;
    }

    cout << "Comparisons = " << comparisons << endl;

    return 0;
}