class Solution {
public:
	std::vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
    	memo = vector<vector<int>>(word1.size(),vector<int>(word2.size(),-1));
        return solve(0,0,word1,word2);
    }
    int solve(int i,int j,string &a,string &b){
    	if(i==a.size())return b.size()-j;
    	if(j==b.size())return a.size()-i;
    	int &ret = memo[i][j];
    	if(~ret)return ret;
    	if(a[i]==b[j])return ret = solve(i+1,j+1,a,b);
    	ret = min(1+solve(i+1,j,a,b),1+solve(i,j+1,a,b)); // delete
    	ret = min(ret,1+solve(i+1,j+1,a,b)); //replace
    	return ret;
    }
};