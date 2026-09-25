class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int writeIndex = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[writeIndex] = nums[i];
                writeIndex++;
            }
        }

        // Fill the remaining positions with zero
        while (writeIndex < nums.size()) {
            nums[writeIndex] = 0;
            writeIndex++;
        }
    }
};