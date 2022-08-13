class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n=matrix.size();
        
        int tot=n*n;
        
        int st=matrix[0][0];
        int en=matrix[n-1][n-1];
        
        int ans=0;
        
        while(st<=en){
            
            int mid = (st+en)/2;
            int count=0;
            
            for(auto i:matrix){
                count+=upper_bound(i.begin(),i.end(),mid)-i.begin();
            }
            
            if(count<k){
                st=mid+1;
            }
            else{
                for(auto i:matrix){
                    if(binary_search(i.begin(),i.end(),mid)){
                        ans=mid;
                        break;
                    }
                }
                en=mid-1;
            }  
        }
        return ans;
    }
};