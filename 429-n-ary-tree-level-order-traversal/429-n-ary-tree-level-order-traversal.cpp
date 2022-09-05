/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int n =q.size();
            vector<int>ans;

            for(int i=0;i<n;i++){

                Node* top = q.front();
                q.pop();
                for(auto it:top->children){
                    q.push(it);
                }
                ans.push_back(top->val);
            }
            res.push_back(ans);
        }
        return res;
    }
};