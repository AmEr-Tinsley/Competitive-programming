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
    vector<TreeNode *> generateTrees(int n){
        return go(1, n);
    }
    
    vector<TreeNode*> go(int l, int r) {
        vector<TreeNode*> ret;
        if (l > r){
        	ret.push_back(nullptr);
        	return ret;
        } 
            
        for (int i = l; i <= r; i++){
            vector<TreeNode*> left = go(l, i - 1);
            vector<TreeNode*> right = go(i + 1, r);
            for (int j = 0; j < left.size(); ++j){
                for (int k = 0; k < right.size(); ++k){
                    TreeNode *node = new TreeNode(i);
                    node->left = left[j];
                    node->right = right[k];
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
  	
  	
    
};