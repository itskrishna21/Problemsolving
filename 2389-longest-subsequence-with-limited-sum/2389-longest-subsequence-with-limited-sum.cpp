class Solution {
public:
    
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        
        int n =nums.size();
        
        sort(nums.begin(),nums.end());
        vector<int>res;
        vector<int>pre(n);
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        
        for(auto i:q){
            int k = upper_bound(pre.begin(),pre.end(),i)-pre.begin();
            res.push_back(k);
        }
        
        return res;
    }
};