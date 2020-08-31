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
	map<int,pair<long long,long long>>index;
	long long ans;
    int widthOfBinaryTree(TreeNode* root) {
    	ans = 0;
        dfs(1,1,root);
        return ans;
    }
    void dfs(int indx,int depth,TreeNode* node){
    	if(node == nullptr)return;
    	if(!index.count(depth)){
    		index[depth] = {indx,indx};
    	}
    	else	index[depth] = {min(indx,index[depth].first),
    							max(indx,index[depth].second)};
    	ans = max(ans,index[depth].second-index[depth].first+1);
    	dfs(indx*2,depth+1,node->left);
    	dfs(indx*2+1,depth+1,node->right);
    }
};