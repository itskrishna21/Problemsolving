class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        
        
        //intution is that ...pair elements will start at even index and end at odd index 
        // but after single element, element will start at odd index and end at even index
        
        int size=nums.size();
        int st=0;
        int en=size;
        
        // check boundary elements first
        if(size==1){
            return nums[0];
        }
        
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[size-1]!=nums[size-2]){
            return nums[size-1];
        }
        
        while(st<=en){
            int mid=st+(en-st)/2;
            if((mid+1<size && nums[mid]!=nums[mid+1]) && (mid-1>=0 && nums[mid]!=nums[mid-1])){
                return nums[mid];
            }
            else{
                if(mid-1>=0 && nums[mid]==nums[mid-1]){
                    if(mid%2==0){
                        en=mid-1;
                    }
                    else{
                        st=mid+1;
                    }
                    
                }
                else{
                    if(mid%2==0){
                        st=mid+1;
                    }
                    else{
                        en=mid-1;
                    }
                }
            }
        }
        return -1;
        
        
    }
};