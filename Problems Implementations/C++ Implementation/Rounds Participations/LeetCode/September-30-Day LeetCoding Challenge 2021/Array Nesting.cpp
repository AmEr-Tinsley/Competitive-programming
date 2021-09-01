class Solution {
public:
	std::vector<int> g[100005];
	std::vector<bool> vis;
	int ans = 0;
	int curr = 0;
    int arrayNesting(vector<int>& nums) {
    	vis.resize(nums.size());
        for(int i =0;i<nums.size();i++){
        	g[i].push_back(nums[i]);
        	g[nums[i]].push_back(i);
        }

        for(int i = 0;i<nums.size();i++){
        	curr = 0;
        	dfs(i);
        	
        	ans = max(ans,curr);
        }

        return ans;
    }

    void dfs(int u){
    	curr++;
    	if(vis[u])return;
    	vis[u] = 1;
    	for(auto v : g[u]){
    		if(!vis[v])dfs(v);
    	}
    }
};