class Solution {
public:
    int pivot(vector<int>nums){
        int st=0;
        int en=nums.size()-1;
        int size=nums.size();
        
        while(st<=en){
            int mid=st+(en-st)/2;
            int before=(mid-1+size)%size;
            int after = (mid+1)%size;
            
            
            if((nums[mid]>nums[before]) && (nums[mid]>nums[after])){
                return mid;
            }
            else{
                if(nums[mid]<nums[size-1]){
                    // st=mid+1;
                    en=mid-1;
                }
                else{
                    // en=mid-1;
                    st=mid+1;
                }
            }
        }
        return size;
    }
    
    int binarysearch(vector<int>nums,int s,int e,int target){
        int st=s;
        int en=e;
        
        while(st<=en){
            int mid=(st+en)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return -1;
    }
    
    
    int search(vector<int>& nums, int target) {
        int p= pivot(nums);
        cout<<p<<" ";
        
        int size=nums.size();
        if(p==size){
            return binarysearch(nums,0,p-1,target);
        }
        if(size==1){
            if(nums[0]==target){
                return 0;
            }
            return -1;
        }
        int c=-1;
        if(binarysearch(nums,p+1,size-1,target)!=-1){
            return binarysearch(nums,p+1,size-1,target);
        }
        else{
            return binarysearch(nums,0,p,target);
        }

        
        return c;        
    }
};