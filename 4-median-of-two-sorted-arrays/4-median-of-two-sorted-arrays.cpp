class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1=nums1.size();
        int n2=nums2.size();
        
        if(n1>n2){
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int st=0;
        int en=n1;
        
        while(st<=en){
            
            int cut1 = (st+en)/2;
            
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int l1 =INT_MIN;
            int l2 =INT_MIN;
            
            int r1=INT_MAX;
            int r2=INT_MAX;
            
            if(cut1!=0){
                l1=nums1[cut1-1];
            }
            if(cut2!=0){
                l2=nums2[cut2-1];
            }
            if(cut1!=n1){
                r1=nums1[cut1];
            }
            if(cut2!=n2){
                r2=nums2[cut2];
            }
            
            if(l1<=r2 && l2<=r1){
                if((n1+n2)%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return max(l1,l2);
                }
                
            }
            else{
                if(l1>r2){
                    en= cut1-1;
                }
                else{
                    st=cut1+1;
                }
            }
            
        }
        return 0.0;
    }
};