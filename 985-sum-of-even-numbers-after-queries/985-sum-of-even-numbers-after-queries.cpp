class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = nums.size();
        vector<int>res;
        int sum = 0;
        
        for(auto i:nums)
        {
            if(i%2==0)
            {
                sum+=i;
            }
        }
        
        for(int i = 0;i<queries.size();i++)
        {
            int t = nums[queries[i][1]];
            // if queries is even
            if(queries[i][0]%2==0)
            {
                // if nums[i] is even
                if(nums[queries[i][1]]%2==0)
                {
                    
                    nums[queries[i][1]]+=queries[i][0];
                    sum+=nums[queries[i][1]]-t;
                }
                // if nums[i] is odd
                else
                {
                    nums[queries[i][1]]+=queries[i][0];
                }
            }
            // if query is odd
            else
            {
                // if nums[i] is even
                if(nums[queries[i][1]]%2==0)
                {
                    sum-=nums[queries[i][1]];
                    nums[queries[i][1]]+=queries[i][0];
                }
                // if nums[i] is odd;
                else
                {
                    nums[queries[i][1]]+=queries[i][0];
                    sum+=nums[queries[i][1]];
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};