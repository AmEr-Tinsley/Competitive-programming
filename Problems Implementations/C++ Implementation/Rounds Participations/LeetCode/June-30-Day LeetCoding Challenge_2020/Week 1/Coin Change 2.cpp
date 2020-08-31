class Solution {
public:
	vector<vector<int>>memo;
    int change(int amount, vector<int>& coins) {
    	memo = vector<vector<int>>(coins.size(),vector<int>(amount+1,-1));
     	return solve(0,0,coins,amount);   
    }
    int solve(int indx,int curr ,vector<int>&a,int amount){
    	if(curr == amount)return 1;
    	if(indx == a.size())return 0;
    	int &ret = memo[indx][curr];
    	if(~ret)return ret;
    	ret = 0;
    	for(int i=0;;i++){
    		if(curr+i*a[indx]<=amount){
    			ret+=solve(indx+1,curr+i*a[indx],a,amount);
    		}
    		else break;
    	}
    	return ret;
    }
};