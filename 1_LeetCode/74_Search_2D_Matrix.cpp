class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size(),m=matrix[0].size(),mid;
       int i=0,j=n*m-1;
       while(i<=j)
       {
             mid = (i+j)/2;
             if(matrix[mid/m][mid%m] == target)
             {
                return true;
             }
             else if(matrix[mid/m][mid%m] > target)
             {
                j=mid-1;
             }
             else
             {
                i=mid+1;
             }
       } 
       return false;
    }
};