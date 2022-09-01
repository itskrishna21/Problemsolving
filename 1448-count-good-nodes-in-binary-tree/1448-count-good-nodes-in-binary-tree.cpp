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
    void gn(TreeNode* root,int& ans,int maxi){
        if(root==NULL){
            return;
        }
        if(maxi<=root->val){
            ans++;
            maxi=root->val;
        }
        gn(root->left,ans,maxi);
        gn(root->right,ans,maxi);
    }
    
    
    int goodNodes(TreeNode* root) {
        int ans=0;
        int maxi=root->val;
        
        gn(root,ans,root->val);
        
        return ans;
    }
};