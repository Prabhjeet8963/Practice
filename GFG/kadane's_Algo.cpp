
class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int max_sum = INT_MIN;
        int sum=0;
        for (int i=0;i<arr.size();i++){
            sum= sum+arr[i];
            max_sum=max(max_sum,sum);
            if(sum<0)
            sum=0;
        }
        return max_sum;
    }
};