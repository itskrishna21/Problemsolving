class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n =nums.size();
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0 || nums[i-1]!=nums[i])
            {
                int t = -1*nums[i];
                
                int a = i+1;
                int b = n-1;
                
                while(a<b)
                {
                    if(nums[a]+nums[b]==t)
                    {
                        res.push_back({nums[i],nums[a],nums[b]});
                        while(a+1<n && nums[a]==nums[a+1])
                        {
                            a++;
                        }
                        while(b-1>=0 && nums[b]==nums[b-1])
                        {
                            b--;
                        }
                        a++;
                        b--;
                    }
                    else if(nums[a]+nums[b]>t)
                    {
                        b--;
                    }
                    else{
                        a++;
                    }
                }
            }
        }
        return res;
    }
};