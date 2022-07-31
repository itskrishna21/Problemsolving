class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
//         int ans=0;
        
//         int count_zero=0;
        
//         for(auto i:nums){
//             if(i==0){
//                 count_zero++;
//             }
//         }
        
//         int size=nums.size();
        
//         if(count_zero==size){
//             return 0;
//         }
        
//         size-=count_zero;
        
//         while(count_zero!=size){
//             ans++;
//             int min_element=INT_MAX;
//             for(auto i:nums){
//                 if(i>0 && i<min_element){
//                     min_element=i;
                    
//                 }
//             }
//             int zeroes=0;
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]>0)
//                 {
//                     nums[i]=nums[i]-min_element;
//                 }
//                 if(nums[i]==0){
//                     zeroes++;
//                 }
//             }
//             if(zeroes==nums.size()){
//                 count_zero=size;
//             }
//         }
//         return ans;
        
        // approach 2
        int count_zero=0;
        
        for(auto i:nums){
            if(i==0){
                count_zero++;
            }
        }
        
        unordered_set<int>s(nums.begin(),nums.end());
        return s.size()-s.count(0);
    }
};