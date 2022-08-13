class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto i:words){
            mp[i]++;
        }
        
        int wordcount=words.size();
        int win_size=wordcount * words[0].size();
        
        int wordsize=words[0].size();

        int n=s.size();
        
        vector<int>ans;
        
        for(int i=0;i<n-win_size+1;i++){
            unordered_map<string,int>temp;

            for(int j=i;j<i+win_size;j+=wordsize){
                string a=s.substr(j,wordsize);
                temp[a]++;
            }
            
            bool f=true;
            for(auto &it:mp){
                if(mp[it.first]!=temp[it.first]){
                    f=false;
                    break;
                }
            }
            if(f){
                ans.push_back(i);
            }
            
            
        }
        return ans;
        
    }
};