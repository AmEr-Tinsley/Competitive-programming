/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), 
 								left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	int parx = -1, pary = -1 , depx , depy,X,Y;
    bool isCousins(TreeNode* root, int x, int y) {
    	X = x;
    	Y = y;
        dfs(root,-1,0);
        return (depx == depy && parx!=pary);
    }
    void dfs(TreeNode* node,int par,int dep){
    	if(node->val == X){
    		parx = par;
    		depx = dep;
    	}
    	else if(node->val == Y){
    		pary = par;
    		depy = dep;
    	}
    	if(node->left){
    		dfs(node->left,node->val,dep+1);
    	}
    	if(node->right){
    		dfs(node->right,node->val,dep+1);
    	}
    }
};