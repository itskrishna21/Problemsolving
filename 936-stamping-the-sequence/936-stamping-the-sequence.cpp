class Solution {
public:
    bool canReplace(string& t, string& s, int i){
        for(int j = 0; j < s.size(); j++){
            if(t[i+j] != s[j] && t[i+j] != '?') return false;
        }
        return true;
    }
    
    int replace(string& t, int i, int n, int cnt){
        for(int j = 0; j < n; j++){
            if(t[i+j] != '?'){
                t[i+j] = '?';
                cnt++;
            }
        }
        return cnt;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int>v;
        int cnt = 0;
        int st = target.size();
        int ss = stamp.size();
        vector<bool>vis(st,false);
        while(cnt != st){
            bool flag = false;
            for(int i = 0; i <= st-ss; i++){
                if(!vis[i] && canReplace(target, stamp, i)){
                    vis[i]= true;
                    flag = true;
                    cnt = replace(target, i, ss, cnt);
                    v.push_back(i);    
                    if(cnt == st) break;
                }
            }
            if(!flag) return {};
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
