class Solution {
public:
	int ans;
	std::vector<int> dx = {1,-1,0,0};
	std::vector<int> dy = {0,0,1,-1};
	int n , m;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int x , y;
        n = grid.size() , m = grid[0].size();

        for(int i = 0;i<n;i++){
        	for(int j = 0;j<m;j++){
        		if(grid[i][j] == 1)x = i , y = j;
        	}
        }
        ans = 0;
        dfs(x,y,grid);
        return ans;
    }
    void dfs(int x,int y,vector<vector<int>>& grid){
    	if(grid[x][y] == 2){
    		ans+=check(grid);
    		return;
    	}
    	grid[x][y] = -1;
    	for(int i = 0;i<4;i++){
    		int xx = dx[i] , yy = dy[i];
			if(ok(x+xx,y+yy,grid)){
				dfs(x+xx,y+yy,grid);
			}
    	}
    	grid[x][y] = 0;
    	return;
    }
    int check(vector<vector<int>>& grid){
    	for(int i = 0;i<n;i++){
    		for(int j = 0;j<m;j++){
    			if(grid[i][j] == 0)return 0;
    		}
    	}
    	return 1;
    }
    bool ok(int x,int y,vector<vector<int>>& grid){
    	return (x<n && y<m && x>=0 && y>= 0 && (grid[x][y]!=-1));
    }	
};