class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2));
        if(n == 1)return nums[0];
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        dp[1][0] = nums[1];
        dp[1][1] = nums[0];
        for(int i = 2;i<n;i++){
            dp[i][0] = max(dp[i-2][0] + nums[i],dp[i-1][0]);
            dp[i][1] = max(dp[i-2][1] + nums[i],dp[i-1][1]);
            if(i == n-1)dp[i][1] = dp[i-1][1];
        }
        
        return max(dp[n-1][0],dp[n-1][1]);
    }
};