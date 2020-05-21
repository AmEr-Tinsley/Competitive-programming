class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
    		int n = matrix.size();
    		int m = matrix[0].size();
        	vector<vector<int>> pref(n+1,vector<int>(m+1));

        	for(int i=1;i<=n;i++){
        		for(int j=1;j<=m;j++){
        			pref[i][j] = pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1] + matrix[i-1][j-1];
        		}
        	}
        	int ret =  0;
        	for(int i=1;i<=n;i++){
        		for(int j=1;j<=m;j++){
        			for(int k =1 ;k <= min(j,i);k++){
        				int got = pref[i][j] - pref[i][j-k] - pref[i-k][j] + pref[i-k][j-k];
        				if(got == k*k)ret++;
        			}
        		}
        	}
        	return ret;
    }
};