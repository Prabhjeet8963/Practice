class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_s= INT_MIN;
        int sum=0;

        for(int i= 0 ; i< nums.size();i++){
            sum +=nums[i];
            max_s= max(max_s,sum);

            if(sum<0)
            sum = 0;
        } 
        return max_s;
    }
};