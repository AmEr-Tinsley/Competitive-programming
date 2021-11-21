class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        map<string,bool>dict;
        vector<bool>dp(n);
        for(auto s : wordDict)dict[s] = 1;
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                string x = s.substr(i,j-i+1);
                if(dict.count(x)){
                    if(i){
                        dp[j] = dp[j] || dp[i-1];
                    }
                    else{
                        dp[j] = 1;
                    }
                }
            }
        }
                
        return dp[n-1];
    }
};