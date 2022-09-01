class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1=INT_MAX,m2=INT_MAX;
        int c1=0,c2=0;
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(m1==nums[i]){
                c1++;
            }
            else if(m2==nums[i]){
                c2++;
            }
            else if(c1==0){
                m1=nums[i];
                c1++;
            }
            else if(c2==0){
                m2=nums[i];
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(auto i:nums){
            if(i==m1){
                c1++;
            }
            else if(i==m2){
                c2++;
            }
        }
        if(c1>(floor(n/3))){
            ans.push_back(m1);
        }
        if(c2>floor(n/3)){
            ans.push_back(m2);
        }
        return ans;
    }
};