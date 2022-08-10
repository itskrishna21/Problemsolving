class Solution {
public:
    int findnum(vector<int>nums1,vector<int>nums2,int size){
        int st=-1000001;
        int en=1000001;
        
        int ans=INT_MAX;
        while(st<=en){
            int mid = (st+en)/2;
            int count=0;
            int ind=upper_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
            count+=ind;
            int ind2=upper_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
            count+=ind2;
            
            if(count<size){
                st=mid+1;
            }
            
            else{
                ans=min(ans,mid);
                en=mid-1;
            }
            
        }
        return ans;
        
    }
    
    
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans=0;
        int size=nums1.size()+nums2.size();
        
        if(size%2!=0){
            ans=findnum(nums1,nums2,size/2+1);
            return ans;
        }
        else{
            double first=findnum(nums1,nums2,size/2);
            double second=findnum(nums1,nums2,size/2+1);
            cout<<first<<" "<<second<<" ";
            double b=(first+second)/2;
            return b;
        }
        return ans;
        
    }
};