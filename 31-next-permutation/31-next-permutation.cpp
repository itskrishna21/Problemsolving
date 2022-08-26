class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int fd=-1;
        int n = nums.size();
        for(int i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){
                fd=i-1;
                break;
            }
        }
        if(fd==-1){
            sort(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[fd]<nums[i]){
                swap(nums[fd],nums[i]);
                break;
            }
        }
        sort(nums.begin()+fd+1,nums.end());
    }
};