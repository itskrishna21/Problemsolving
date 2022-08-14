class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int ans=INT_MAX;
        int n=nums.size();
        
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        reverse(suffix.begin(),suffix.end());
        
        if(binary_search(prefix.begin(),prefix.end(),x)){
            int ind=lower_bound(prefix.begin(),prefix.end(),x)-prefix.begin();
            ans=min(ans,ind+1);
        }
        if(binary_search(suffix.begin(),suffix.end(),x)){
            int ind=lower_bound(suffix.begin(),suffix.end(),x)-suffix.begin();
            ans=min(ans,ind+1);
        }
        
        for(int i=0;i<prefix.size();i++){
            if(binary_search(suffix.begin(),suffix.end(),x-prefix[i])){
                int ind = lower_bound(suffix.begin(),suffix.end(),x-prefix[i])-suffix.begin()+1;
                int temp=i+1+ind;
                ans=min(ans,temp);
            }
            
        }
        if(ans==INT_MAX || ans>n){
            return -1;
        }
        
        return ans;
    }
};