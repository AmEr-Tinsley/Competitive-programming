class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ret = 0;
        for(int i = 0;i<n;i++){
        	for(int j = 0;j<m;j++){
        		if(grid[i][j]){
        			ret+=4;
        			ret-=(i-1 >= 0 && grid[i-1][j]);
        			ret-=(j-1 >= 0 && grid[i][j-1]);
        			ret-=(i+1 < n && grid[i+1][j]);
        			ret-=(j+1 < n && grid[i][j+1]);
        		}
        	}
        }
        return ret;
    }
};