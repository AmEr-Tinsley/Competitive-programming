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
	int ret = 0;
    int sumRootToLeaf(TreeNode* root) {
        go(root,vector<int>(0));
        return ret;
    }

    void go(TreeNode* curr,vector<int>v){
    	v.push_back(curr->val);
    	if((curr->left == curr->right) && curr->left == nullptr){
    		reverse(v.begin(),v.end());
    		for(int i = 0;i<v.size();i++)if(v[i])ret+=(1<<i);
    		return;
    	}
    	if(curr->left != nullptr){
    		go(curr->left,v);
    	}
    	if(curr->right != nullptr){
    		go(curr->right,v);
    	}

    }
    
};