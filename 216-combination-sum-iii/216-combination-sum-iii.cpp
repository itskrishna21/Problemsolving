class Solution {
public:
    void combi(vector<int>candidates, int target, vector<vector<int>>&ans, vector<int>&curr, int currind,int currsum,int k){
        
        if(currsum==target){
            if(curr.size()==k){
                ans.push_back(curr);
            }
            
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
            combi(candidates,target,ans,curr,i+1,currsum,k);
            currsum-=candidates[i];
            curr.pop_back();
        }
        
    }
    
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>candidates={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>curr;
        sort(candidates.begin(),candidates.end());
        combi(candidates,n,ans,curr,0,0,k);
        return ans;
        
    }
};