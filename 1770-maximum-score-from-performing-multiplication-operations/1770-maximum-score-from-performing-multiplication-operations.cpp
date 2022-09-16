class Solution {
public:
    int score(int i,int j, vector<int>&nums, vector<int>&arr,int ind,vector<vector<int>>&dp){
        if(ind>=arr.size())
        {
            return 0;
        }
        if(dp[i][ind]!=INT_MIN){
            return dp[i][ind];
        }
        
        int lsum = nums[i]*arr[ind]+score(i+1,j,nums,arr,ind+1,dp);
        int rsum = nums[j]*arr[ind]+score(i,j-1,nums,arr,ind+1,dp);
        
        return dp[i][ind]=max(lsum,rsum);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size();
        int m = multipliers.size();
        
        vector<vector<int>>dp(m,vector<int>(m,INT_MIN));
        
        int res = score(0,n-1, nums, multipliers,0,dp);
        
        return res;
    }
};