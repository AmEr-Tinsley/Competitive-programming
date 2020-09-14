class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        std::vector<int> dp(n);
        int ans = 0;
        for(int i = 0;i<n;i++){
        	dp[i] = nums[i];
        	for(int j = 0;j<i-1;j++){
        		dp[i] = max(dp[i] , dp[j] + nums[i]);
        	}
        	ans = max(ans,dp[i]);
        }
        return ans;
    }
};