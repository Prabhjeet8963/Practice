class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
       int xorVal=0;

       for (int i= 1 ; i<= n;i++){
        xorVal ^= i;
       }

       for(int arr : nums){
        xorVal ^= arr;
       }
       return xorVal;
    }
};