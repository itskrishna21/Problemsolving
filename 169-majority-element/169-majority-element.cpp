class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int res = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                res=nums[i];
                count++;
            }
            else{
                if(res==nums[i]){
                    count++;
                }
                else{
                    count--;
                }
            }
        }
        return res;
    }
};