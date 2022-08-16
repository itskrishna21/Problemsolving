class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                nums[i-1]=1;
            }
            else{
                nums[i-1]=-1;
            }
        }
        int ans=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==-1){
                return i;
            }
        }
        
        return ans;
    }
};