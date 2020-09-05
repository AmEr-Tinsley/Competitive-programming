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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> ret;
        go(root1,ret);
        go(root2,ret);
        sort(ret.begin(),ret.end());
        return ret;
    }
    void go(TreeNode* curr,vector<int>&ret){
    	if(curr == nullptr)return;
    	ret.push_back(curr->val);
    	if(curr->left != nullptr)go(curr->left,ret);
    	if(curr->right != nullptr)go(curr->right,ret);
    }
};