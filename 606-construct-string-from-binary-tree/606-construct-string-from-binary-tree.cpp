/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
*/
class Solution {
public:
    void preorder(vector<string>& ans , TreeNode* root){
        if(!root){
            return;
        }else{
            ans.push_back("(");
            ans.push_back(to_string(root->val));
            
            preorder(ans , root->left);
            if(!root->left && root->right){
                ans.push_back("()");
            }
            preorder(ans , root->right);
            
            ans.push_back(")");
            return;
        }       
    }
    
    
    string tree2str(TreeNode* root) {
        vector<string> ans;
        preorder(ans , root);
        string s = "";
        for(int i = 1 ; i < ans.size() - 1 ; i++){
            s += ans[i];
        }
        return s;
    }
};