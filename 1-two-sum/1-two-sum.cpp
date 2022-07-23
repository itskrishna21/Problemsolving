class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();i++){
            vector<int>ans;
            ans.push_back(i);
            int k=target-nums[i];
            if(mp.find(k)!=mp.end()){
                if(i!=mp[target-nums[i]]){
                    ans.push_back(mp[target-nums[i]]);
                    return ans;
                }
            }
        }
        return nums;
    }
};