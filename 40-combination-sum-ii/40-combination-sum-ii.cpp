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
            if(i!=currind && candidates[i]==candidates[i-1]){
                continue;
            }
            currsum+=candidates[i];
            curr.push_back(candidates[i]);
            combi(candidates,target,ans,curr,i+1,currsum);
            currsum-=candidates[i];
            curr.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        combi(candidates,target,ans,curr,0,0);
        return ans;

    }
};