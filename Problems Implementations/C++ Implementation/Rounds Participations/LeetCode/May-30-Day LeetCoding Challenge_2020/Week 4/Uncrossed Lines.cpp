class Solution {
public:
	int n,m;
	std::vector<int> a;
	std::vector<int> b;
	std::vector<std::vector<int>> memo;
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
         n = A.size();
         m = B.size();
         memo = vector<vector<int>>(n,vector<int>(m,-1));
         a = A;
         b = B;
         return solve(0,0);
    }

    int solve(int i,int j){
    	if(i==n || j==m)return 0;

    	int &ret = memo[i][j];
    	if(~ret)return ret;
    	if(a[i] == b[j]) ret = max(ret,solve(i+1,j+1)+1);
    	ret = max(ret,max(solve(i+1,j),solve(i,j+1)));
    	return ret;
    }
};