class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    	if(k<=1)return 0;
     	int mn = 10005;
     	int ret = 0;
     	for(auto x : prices){
     		ret = max(ret,x-mn);
     		mn = min(mn,x);
     	}   
     	return ret;
    }
};