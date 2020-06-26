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
    int sumNumbers(TreeNode* root) {
    	if(root==nullptr)return 0;
  		return go(root,"");     
    }
    int go(TreeNode* node,string curr){
    	int L = 0  , R = 0;
    	if(curr.size() != 0 || (curr.size() == 0 && node->val > 0 ))
    	curr+=char('0'+node->val);
    	if(node->left == nullptr && node->right == nullptr){
    		long long cnt = 1 , ret = 0;
    		while(curr.size()){
    			ret+=cnt*(curr.back()-'0');
    			curr.pop_back();
    			if(curr.size())cnt*=10;
    		}
    		return ret;
    	}
    	if(node -> left!=nullptr){
    		L = go(node->left,curr);
    	}
    	if(node -> right != nullptr){
    		R = go(node->right,curr);
    	}
    	return L + R;
    }
};