class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        int res = 0;
        
        vector<int>prefix(n);
        vector<int>suffix(n);
        
        prefix[0]=height[0];
        suffix[n-1]=height[n-1];
        
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],height[i]);
            suffix[n-1-i]=max(suffix[n-i],height[n-1-i]);
        }
        
        for(int i=0;i<n;i++)
        {
            res+=min(prefix[i],suffix[i])-height[i];
        }
        return res;
    }
};