class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++){
            int st = 0;
            int en = n-1;
            while(st<=en){
                swap(matrix[i][st],matrix[i][en]);
                st++;
                en--;
            }
        }
    }
};