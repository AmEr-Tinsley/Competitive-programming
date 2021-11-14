class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return true;
        vector<int>dp(n+1);
        for(int i = 0;i<n;i++){
            if(i)dp[i]+=dp[i-1];
            if(dp[i] || i == 0){
                if(nums[i]){
                    dp[i+1]++;
                    int nxt = min(n,i + nums[i] + 1);
                    dp[nxt]--; 
                }
            }
        }
        
        return (dp[n-1] > 0);
    }
};