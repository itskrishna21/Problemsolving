class Solution {
public:
    string pushDominoes(string dominoes) {
        deque<int> q;
        vector<bool> ignore(dominoes.length());
        for(int i=0; i<dominoes.length(); i++)
            if(dominoes[i]!='.') q.push_back(i);
        while(!q.empty()) {
            int i = q.front();
            char direction = dominoes[i];
            q.pop_front();
            if(ignore[i]) {
                ignore[i]=false;
                continue;
            }
            if(direction == 'L') {
                if(i>0 && dominoes[i-1] == '.') {
                    dominoes[i-1] = 'L';
                    q.push_back(i-1);
                }
            } 
            else if(direction == 'R') {
                if(i<dominoes.length()-2 && dominoes[i+2] == 'L') {
                    ignore[i+2]=true;
                }
                else if(i<dominoes.length()-1 && dominoes[i+1] == '.') {
                    dominoes[i+1] = 'R';
                    q.push_back(i+1);
                }
            }
        }
        return dominoes;
     }
};
