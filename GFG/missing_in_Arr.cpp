#include <vector>

class Solution {
public:
    int missingNumber(vector<int>& arr) {
       
        long long n = arr.size() + 1;
        
        long long expectedSum = (n * (n + 1)) / 2;
        long long actualSum = 0;
        
        for (int num : arr) {
            actualSum += num;
        }
        
        return expectedSum - actualSum;
    }
};