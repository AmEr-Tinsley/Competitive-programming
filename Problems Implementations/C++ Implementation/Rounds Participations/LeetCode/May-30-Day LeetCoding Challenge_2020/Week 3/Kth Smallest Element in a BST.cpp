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
	int cnt = 0;
	int K;
	int ans;
    int kthSmallest(TreeNode* root, int k) {
    	K = k;
        go(root);
        return ans;
    }
    void go(TreeNode* node){
    	
    	if(cnt>K)return;
    	if(node->left)go(node->left);
    	cnt++;
    	if(cnt==K){
    		ans = node->val;
    		return;
    	}
    	if(node->right)go(node->right);
    }
};