class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        
        for(int i=0;i<numRows;i++){
            ans[i].resize(i+1,1);   //every ith vector will have i+1 elements
            for(int j=1;j<i;j++){   //starting from j=1 cuz oth element will always be zero and ending at j<i cuz last element will be 1
                ans[i][j]=ans[i-1][j]+ans[i-1][j-1];
                
            }
            
        }
        return ans;
    }
};