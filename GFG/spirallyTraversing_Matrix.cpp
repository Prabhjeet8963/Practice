class Solution {
  public:

    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int n=mat.size(),m=mat[0].size();
        int left=0,right=m-1,top=0,bottom=n-1,dir=0;
        vector<int>v;
        while(left<=right && top<=bottom)
        {
            if(dir==0)
            {
                for(int i=left;i<=right;i++)
                {
                    v.push_back(mat[top][i]);
                }
                top++;
            }
            if(dir==1)
            {
                for(int i=top;i<=bottom;i++)
                {
                    v.push_back(mat[i][right]);
                }
                right--;
            }
            if(dir==2)
            {
                for(int i=right;i>=left;i--)
                {
                    v.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            if(dir==3)
            {
                for(int i=bottom;i>=top;i--)
                {
                    v.push_back(mat[i][left]);
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return v;
    }
};