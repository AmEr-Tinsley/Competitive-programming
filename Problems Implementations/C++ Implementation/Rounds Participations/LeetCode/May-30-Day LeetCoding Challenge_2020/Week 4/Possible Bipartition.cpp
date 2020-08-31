class Solution {
public:
	vector<vector<int>>g;
	std::vector<bool> vis;
	std::vector<int> col;
	bool yes = false;
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        	g = vector<vector<int>>(N+1);
        	vis = vector<bool>(N+1,0);
        	col = std::vector<int>(N+1);
        	for(auto p : dislikes)g[p[0]].push_back(p[1]),
        						  g[p[1]].push_back(p[0]);
        	bool ret = true;
        	for(int i = 1;i<=N;i++)if(!vis[i])ret&=dfs(i);
        	return ret;
    }

    bool dfs(int u){
    	vis[u]=1;
    	for(auto v : g[u]){
    		if(!vis[v]){
    			col[v] = !col[u];
    			if(!dfs(v))return false;
    		}
    		if(col[u]==col[v])return false;
    	}
    	return true;
    }
};