class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,1e9);
        dp[1]= cost[1];
        dp[0] = cost[0];
        
        for(int i = 0;i<n;i++){
            dp[i+1] = min(dp[i+1],dp[i] + cost[i+1]);
            if(i+2 <= n){
                dp[i+2] = min(dp[i+2],dp[i] + cost[i+2]);
            }
        }
        
        return dp[n];
    }
};