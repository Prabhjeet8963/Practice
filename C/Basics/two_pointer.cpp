//reversing a string , using two pointers approach 


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

    int left = 0;
    int right = n - 1;

    // Two-pointer approach
    while (left < right) {
        swap(arr[left], arr[right]);

        left++;
        right--;
    }

    // Print reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

/* left starts at the beginning & right starts at the end.
Swap the two elements.
Move left forward and right backward.
Repeat until they meet. */