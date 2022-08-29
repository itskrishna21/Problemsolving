class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n =s.size();
        
        int res=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]==1){
                res=max(res,j-i+1);
            }
            else{
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    i++;
                }
                res=max(res,j-i+1);
            }
            j++;
        }
        return res;
    }
};