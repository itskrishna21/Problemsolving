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
	unordered_map<int, int> mp;

	void solve(TreeNode* root, int& ans){

		if(!root){
			return;
		}

		mp[root->val]++;

		// In case odd = 0 we have even palindrome
		// In case odd = 1 we have odd palindrome
		if(!root->left && !root->right){

			int odd = 0;

			for(auto i : mp){
				if(i.second % 2 == 1){
					odd++;
				}
			}

			if(odd <= 1){
				ans++;
			}
		}

		solve(root->left, ans);
		solve(root->right, ans);

		mp[root->val]--;
	}


	int pseudoPalindromicPaths (TreeNode* root) {

		int ans = 0;
		solve(root, ans);
		return ans;
	}
};