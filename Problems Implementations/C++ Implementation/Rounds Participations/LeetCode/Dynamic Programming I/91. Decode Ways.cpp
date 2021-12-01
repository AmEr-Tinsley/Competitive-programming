class Solution {
public:
    int numDecodings(string s) {
        s = "#" + s;
        int n = s.size();
        vector<int>dp(n+1);
        dp[0] = 1;
        dp[1] = (s[1] != '0');
        for(int i = 2;i<n;i++){
            if(s[i] != '0'){
                dp[i]+=dp[i-1];
            }    
            if(s[i - 1] == '1'  && (s[i] <= '9'))
                dp[i]+=dp[i-2];
            else if(s[i-1] == '2' && (s[i] <='6'))
                dp[i]+=dp[i-2];
        }
        
        return dp[n-1];
    }
};