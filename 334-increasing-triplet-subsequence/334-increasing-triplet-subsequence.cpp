class Solution {
public:
    int solve(vector<int>nums)
    {
        vector<int>temp;
        temp.push_back(nums[0]);
        int l=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                l++;
            }
            else{
                int ind =lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return l;
    }
    
    bool increasingTriplet(vector<int>& nums) {
        int l = solve(nums);
        return (l>=3);
    }
};