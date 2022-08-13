class Solution {
public:
    
    void combi(vector<int>candidates, int target, vector<vector<int>>&ans, vector<int>&curr, int currind,int currsum){
        
        if(currsum==target){
            ans.push_back(curr);
            return ;
        }
        if(currsum>target)
            return ;
        
        for(int i=currind;i<candidates.size();i++){
            currsum+=candidates[i];
            curr.push_back(candidates[i]);
            combi(candidates,target,ans,curr,i,currsum);
            currsum-=candidates[i];
            curr.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>curr;
        
        combi(candidates,target,ans,curr,0,0);
        return ans;
        
    }
};