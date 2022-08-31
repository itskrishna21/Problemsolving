class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
          vector<string> mp = 
          {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> st;
        for(auto it : words)
        {
            string curr = "";
            for(int i=0;i<it.size();i++)
            {
                curr += mp[it[i]-'a'];
            }
            st.insert(curr);
        }
       return st.size();
    }
};