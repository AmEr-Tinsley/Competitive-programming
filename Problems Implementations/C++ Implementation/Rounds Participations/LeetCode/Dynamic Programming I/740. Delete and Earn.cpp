class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 2*10000;
        vector<int>freq(N+1);
        vector<vector<int>>dp(N+1,vector<int>(2));
        for(auto x : nums)freq[x]++;
        for(int i = 1;i<=N;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = max(dp[i-1][1] , dp[i-1][0] + freq[i]*i);
        }
        return max(dp[N][0],dp[N][1]);
    }
};