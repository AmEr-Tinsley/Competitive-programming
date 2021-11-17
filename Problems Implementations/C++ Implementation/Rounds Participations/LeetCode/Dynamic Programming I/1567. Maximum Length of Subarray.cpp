class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        int lst = -1;
        int first_neg = -1;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] < 0){
                dp[i]++;
            }
            if(i)dp[i]+=dp[i-1];
            if(nums[i] == 0){
                lst = i;
                first_neg = -1;
                continue;
            }
            if(nums[i] < 0 && first_neg == -1){
                first_neg = i;
            }
            
            if(lst == -1 && dp[i]%2 == 0){
                ans = max(ans,i-lst);
            }
            else if(lst >= 0 && (dp[i]-dp[lst])%2 == 0){
                ans = max(ans,i-lst);
            }
            else{
                ans = max(ans,i-first_neg);
            }
        }
        
        return ans;
    }
};