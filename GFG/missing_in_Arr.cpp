//Find missing number from 1 to n

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size() + 1;

        int expectedSum = (n * (n + 1)) / 2;
        int actualSum = 0;

        for (int num : arr) {
            actualSum += num;
        }

        return expectedSum - actualSum;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {0, 1, 2, 4, 5, 6,};

    int result = sol.missingNumber(arr);

    cout << result << endl;

    return 0;
}