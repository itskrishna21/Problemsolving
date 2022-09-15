class Solution {
public:
    vector<int> findOriginalArray(vector<int>& nums) {
        vector<int>res;
        sort(nums.begin(),nums.end());
        int n =nums.size();
        unordered_map<int,int>mp;
        if(n%2){
            return res;
        }
        
        if(*max_element(nums.begin(),nums.end())==0){
            for(int i=0;i<n/2;i++){
                res.push_back(0);
            }
            return res;
        }
        
        for(auto i:nums){
            mp[i]++;
        }
        
        for(auto i:nums){
            if(mp[i]>0){
                mp[i]--;
                if(mp.find(i*2)!=mp.end() && mp[i*2]>0){
                    res.push_back(i);
                    mp[i*2]--;
                }
            }
        }
        if(res.size()!=n/2){
            return {};
        }
        return res;
        
    }
};