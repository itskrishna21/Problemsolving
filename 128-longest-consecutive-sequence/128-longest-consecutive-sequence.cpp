class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()){
            return 0;
        }
        unordered_map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        
        int res=1;
        int c=1;
        
        for(auto i:nums){
            if(mp.find(i-1)==mp.end()){
                int next =i+1;
                while(mp.find(next)!=mp.end()){
                    c++;
                    next++;
                }
                res=max(res,c);
                c=1;
            }
        }
        
        return res;
    }
};