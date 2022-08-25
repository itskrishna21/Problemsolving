class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row=false;
        bool col=false;
        
        //check if 0th row has any zeroes
        for(int i=0;i<matrix[0].size();i++){
            if(matrix[0][i]==0){
                row=true;
                break;
            }
        }
        //check if 0th index of any col has zeroes;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                col=true;
                break;
            }
        }
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;  //make first index of that row zero
                    matrix[0][j]=0;  //make first index of that col zero
                }
            }
        }
        
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][0]==0 || matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        
        // check if bool row is true if true then make whole 0th row 0
        if(row){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i]=0;
            }
        }
        //check if bool col is true if true then make first index of every column 0;
        if(col){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
        
    }
};