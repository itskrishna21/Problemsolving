class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        
        int st=1;
        int en=grades.size();
        
        // int maxi=en/2;
        int size=grades.size();
        int ans=0;
        
        sort(grades.begin(),grades.end());
        
        while(st<=en){
            unsigned long long mid = (st+en)/2;
            
            unsigned long long count=((mid*(mid+1))/2);
             
            if(count<=size){
                st=mid+1;
                ans=mid;
            }
            else{
                en=mid-1;
            }
            
        }
        return ans;
    }
};