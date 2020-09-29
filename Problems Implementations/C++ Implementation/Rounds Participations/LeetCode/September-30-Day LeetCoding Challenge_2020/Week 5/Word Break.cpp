class Solution {
public:
	string a;
	map<string,bool>dp,ex;
    bool wordBreak(string s, vector<string>& wordDict) {
        a = s;
        for(auto x : wordDict)ex[x] = true;
        return solve(0);
    }
    bool solve(int indx){
    	if(indx == a.size())return 1;
    	string curr = "";
    	if(dp.count(a.substr(indx)))return dp[a.substr(indx)];
    	for(int i = indx;i<a.size(); i++){
    		curr+=a[i];
    		if(ex.count(curr)){
    			if(solve(i+1)){
    				dp[a.substr(indx)] = 1;
    				return 1;
    			}
    		}
    	}
    	return 0;
    }
};