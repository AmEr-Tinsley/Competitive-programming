class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
     	int n = costs.size();
     	vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
     	dp[0][0] = 0;
     	for(int i=0;i<n;i++){
     		for(int j=1;j<=i+1;j++){
     			dp[j][i+1-j] = min(dp[j-1][i+1-j]+costs[i][0],dp[j][i+1-j]);
     		}
     		for(int j=1;j<=i+1;j++){
     			dp[i+1-j][j]=min(dp[i+1-j][j-1]+costs[i][1],dp[i+1-j][j]);
     		}
     	}
     	return dp[n/2][n/2];   
    }
};