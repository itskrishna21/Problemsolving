class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int>pq;
        unordered_map<int,int>mp;
        
        for(auto n:arr){
            mp[n]++;
        }
        
        for(auto n:mp){
            pq.push(n.second);
            
        }
        
        int ans=0;
        int c=1;
        int n=arr.size()/2;
        while(ans<n){
            int val=ans+pq.top();
            if(val<n){
                c++;
            }
            pq.pop();
            ans=val;
            
        }
        
        return c;
    }
};