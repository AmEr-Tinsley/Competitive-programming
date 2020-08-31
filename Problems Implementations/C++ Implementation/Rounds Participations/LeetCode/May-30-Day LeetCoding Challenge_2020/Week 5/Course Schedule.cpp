class Solution {
public:
	vector<vector<int>>g;
	std::vector<int> vis;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	g = vector<vector<int>>(numCourses);
    	vis = vector<int>(numCourses);
        for(auto p : prerequisites){
        	g[p[0]].push_back(p[1]);
        }

        for(int i=0;i<numCourses;i++){
        	if(!vis[i]){
        		if(!dfs(i))return false;
        	}
        }
        return true;
    }

    bool dfs(int u){
    	vis[u] = 1;

    	for(auto v : g[u]){
    		if(vis[v]==1){
    			return false;
    		}
    		else if(vis[v]==0){
    			if(!dfs(v)){
    				return false;
    			}
    		}
    	}
    	vis[u]=2;
    	return true;
    }


};