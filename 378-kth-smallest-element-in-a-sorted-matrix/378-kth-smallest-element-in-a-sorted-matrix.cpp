class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        for(auto n:matrix){
            for(auto i:n){
                pq.push(i);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};
