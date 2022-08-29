class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int st = 0;
        int en = mat.size()*mat[0].size()-1;
        
        while(st<=en){
            int mid = (st+en)/2;
            int i = mid/mat[0].size();
            int j =mid%mat[0].size();
            if(mat[i][j]==target){
                return true;
            }
            else if(mat[i][j]<target){
                st = mid+1;
                
            }
            else{
                en =mid-1;
            }
        }
        return false;
    }
};