class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int a =0;
        int b = 0;
        int n = nums.size();
        
        int res = 0;
        while(b<n)
        {
            if(nums[b]==1)
            {
                res = max(res,b-a+1);
                b++;
            }
            else{
                a=b;
                b++;
            }
            if(nums[a]==0)
            {
                a++;
                continue;
            }
        }
        return res;
    }
};