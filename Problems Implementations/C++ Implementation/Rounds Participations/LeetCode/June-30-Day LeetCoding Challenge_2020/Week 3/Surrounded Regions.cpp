class Solution {
public:
	int n,m;
    void solve(vector<vector<char>>& board) {
        n = board.size();
        if(n==0)return;
        m = board[0].size();
        for(int i=0;i<n;i++)dfs(i,0,board),dfs(i,m-1,board);
        for(int j=0;j<m;j++)dfs(0,j,board),dfs(n-1,j,board);
        for(auto &v : board){
        	for(auto &c : v){
        		if(c == 'o')c ='O';
        		else if(c=='O')c='X';
        	}
        }
    }
	bool ok (int x,int y){return (x>=0 && x<n && y>=0 && y<m);}
	void dfs(int x ,int y ,vector<vector<char>>& board ){
		if(!ok(x,y) || board[x][y]!='O')return;
		board[x][y]='o';
		dfs(x-1,y,board),dfs(x+1,y,board),dfs(x,y-1,board),dfs(x,y+1,board);
	}
};