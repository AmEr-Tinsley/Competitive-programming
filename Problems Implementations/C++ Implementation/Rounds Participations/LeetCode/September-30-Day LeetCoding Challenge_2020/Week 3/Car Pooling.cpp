class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>dp(1001);
        for(auto v : trips){
        	dp[v[1]]+=v[0];
        	dp[v[2]]-=v[0];
        }
        for(int i = 0;i<=1000;i++){
        	if(i)dp[i]+=dp[i-1];
        	if(dp[i] > capacity)return false;
        }
        return true;
    }
};