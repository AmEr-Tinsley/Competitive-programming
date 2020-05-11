class Solution {
public:
	int n,m;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        n = image.size();
        m = image[0].size();
        std::vector<std::vector<bool>> vis(n,vector<bool>(m));
        go(sr,sc,image[sr][sc],image,newColor,vis);
        return image;
    }
    std::vector<int> dx={1,-1,0,0};
    std::vector<int> dy={0,0,1,-1};
    bool check(int x,int y){
    	return (x>=0 && x<n && y>=0 && y<m);
    }
    void go(int x,int y,int trg,vector<vector<int>>& image,int c,vector<std::vector<bool>>&vis){
    		image[x][y] = c;
    		vis[x][y] = 1;
    		for(int i=0;i<4;i++){
    				int newx = x + dx[i] , newy = y + dy[i];
    				if(check(newx,newy)){
    					if(image[newx][newy] == trg && !vis[newx][newy]){
    						go(newx,newy,trg,image,c,vis);
    					}
    				}
    		}
    }
};