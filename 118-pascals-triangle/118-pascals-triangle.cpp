class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==1){
            ans.push_back({1});
            return ans;
        }
        ans=generate(numRows-1);
        vector<int>prev=ans[ans.size()-1];
        vector<int>add(numRows,1);
        
        for(int i=1;i<prev.size();i++){
            add[i]=(prev[i]+prev[i-1]);
        }
        ans.push_back(add);
        return ans;
    }
};