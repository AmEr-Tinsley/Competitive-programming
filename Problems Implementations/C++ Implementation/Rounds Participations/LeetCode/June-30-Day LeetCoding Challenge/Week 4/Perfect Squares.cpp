class Solution {
public:
    int numSquares(int n) {
    	int Max = sqrt(n);
    	std::vector<int> dp(n+1,1e9);
    	dp[0]=0;
    	for(int i=1;i<=n;i++){
    		for(int j = 1;j<=Max;j++){
    			if(j*j>i)break;
    			if(j*j == i )dp[i]=1;
    			else	dp[i] = min(dp[i],dp[i-j*j]+1);
    		}
    	}
    	return dp[n];
    }
};