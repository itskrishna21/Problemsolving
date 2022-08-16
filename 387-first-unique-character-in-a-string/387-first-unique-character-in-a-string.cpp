class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mp;
        
        for(auto i:s)
            mp[i]++;
        
        int ans=-1;
        for(int i=s.size()-1;i>=0;i--){
            if(mp[s[i]]==1){
                ans=i;
            }
        }
        return ans;
    }
};