class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int res=0;
        unordered_map<string,int>mp;
        bool flag=true;
        
        
        for(auto i:words)
        {
            mp[i]++;
        }
        
        for(auto i:mp)
        {
            cout<<i.first<<"--"<<i.second<<" ";
        }
        for(int i=0;i<words.size();i++)
        {
            string t=words[i];
            reverse(t.begin(),t.end());
            if(t!=words[i])
            {
                // cout<<mp[t]<<" ";
                res+=(min(mp[words[i]],mp[t]))*4;
            }
            else{
                // cout<<i.first<<"--"<<i.second<<" ";
                if(mp[words[i]]%2==1 && flag)
                {
                    flag=false;
                    res+=(mp[words[i]]*2);
                }
                else
                {
                    int m=mp[words[i]]/2;
                    res+=(m*4);
                }
            }
            mp[words[i]]=0;
            mp[t]=0;
        }
        return res;
    }
};