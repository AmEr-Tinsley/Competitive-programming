class Solution {
public:
	
    int maxProfit(vector<int>& prices) {
    	vector<vector<int>>memo(30005,vector<int>(2,-1));
        return solve(0,1,prices,memo);
    }
    int solve(int indx,int buy,vector<int>&prices,vector<vector<int>>&memo){
    	if(indx == (int)prices.size())return 0;
    	int &ret = memo[indx][buy];
    	if(ret!=-1)return ret;
    	ret = solve(indx+1,buy,prices,memo);
    	ret = max(ret,solve(indx+1,!buy,prices,memo)+(buy?-prices[indx]:prices[indx]));
    	return ret;
    }
};