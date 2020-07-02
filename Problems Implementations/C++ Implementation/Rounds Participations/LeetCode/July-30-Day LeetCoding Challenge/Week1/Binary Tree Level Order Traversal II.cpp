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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ret;
        if(root == nullptr)return ret;
        go(root,0,ret);
        reverse(ret.begin(),ret.end());
        return ret;
    }
    void go(TreeNode* node,int depth,vector<vector<int>>&ret){
    	std::vector<int> v;
    	while(depth >= ret.size())ret.push_back(v);
    	ret[depth].push_back(node->val);
    	if(node->left != nullptr){
    		go(node->left,depth+1,ret);
    	}
    	if(node->right != nullptr){
    		go(node->right,depth+1,ret);
    	}
    }	

};