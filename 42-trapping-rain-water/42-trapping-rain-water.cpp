class Solution {
public:
    int trap(vector<int>& height) {
        
        int  n =height.size();
        int res = 0;
        
        int lmax = 0;
        int rmax = 0;
        
        int a =0;
        int b = n-1;
        
        while(a<b)
        {
            if(height[a]<height[b])
            {
                lmax = max(lmax, height[a]);
                res+=lmax-height[a];
                a++;
            }
            else{
                rmax = max(rmax,height[b]);
                res+=rmax-height[b];
                b--;
            }
        }
        return res;
    }
};