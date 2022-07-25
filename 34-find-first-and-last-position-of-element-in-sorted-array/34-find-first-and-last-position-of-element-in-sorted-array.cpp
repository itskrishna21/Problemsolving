class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        int s=0;
        int e=n-1;
        int a,b;
        a=-1;
        b=-1;
        
        vector<int>ans={a,b};
        //for starting point
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                if((mid-1>=0 && nums[mid-1]==target)){
                    e=mid-1;
                }
                else{
                    a=mid;
                    break;
                }
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        cout<<a;
        //for endinf point;
        s=0;
        e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                if((mid+1<nums.size() && nums[mid+1]==target)){
                    s=mid+1;
                }
                else{
                    b=mid;
                    break;
                }
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        ans={a,b};
        return ans;
    }
};