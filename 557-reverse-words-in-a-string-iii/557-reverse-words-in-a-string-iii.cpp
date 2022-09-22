class Solution {
public:
    string reverseWords(string s) {
        int a = 0;
        int b = 0;
        
        while(b!=s.size())
        {
            if(s[b]!=' ')
            {
                b++;
            }
            else{
                int c = b-1;
                while(a<c)
                {
                    swap(s[a],s[c]);
                    a++;c--;
                }
                a = b+1;
                b++;
            }
        }
            int c = b-1;
            while(a<c)
            {
                swap(s[a],s[c]); 
                a++;c--;
            }
        
        return s;
    }
};