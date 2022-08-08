class Solution {
public:
    
    //-------------recursive soln------------------------
    // time complexity -- O(2^n);
    // space complexity --O(N);
    
    
    int lis(vector<int>nums,int ind,int prev_ind,int n){
        
        if(ind==n){
            return 0;
        }
        
        int len = 0+lis(nums,ind+1,prev_ind,n);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len=max(len,1+lis(nums,ind+1,ind,n));
        }
        return len;
    }
    
    
    
    //------------------- Memoization--------------------
    
//     Time complexity --O(N^2);
//     Space Complexity -O(N^2);
    
    
    int lisdp(vector<int>nums,vector<vector<int>>&dp,int ind,int prev_ind,int n){
        
        if(ind==n){
            return 0;
        }
        if(dp[ind][prev_ind+1]!=-1){
            return dp[ind][prev_ind+1];
        }
        
        int len = 0+lisdp(nums,dp,ind+1,prev_ind,n);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len=max(len,1+lisdp(nums,dp,ind+1,ind,n));
        }
        return dp[ind][prev_ind+1]=len;
    }
    
    //---------------Binary Search------------------------
    
    //Time Complexity --O(NlogN);
    //Space Complexity -O(N);
    int lisbs(vector<int>nums){
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
    
    
    
    
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
//         return lis(nums,0,-1,n);
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        cout<<n;
        // return lisdp(nums,dp,0,-1,n);
        
        return lisbs(nums);
        
        
    }
};