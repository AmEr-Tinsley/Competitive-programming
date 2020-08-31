class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        bool ret = false;
        int wa = -1; 
        int X0 = coordinates[0][0],Y0 = coordinates[0][1];
        int X1 = coordinates[1][0],Y1 = coordinates[1][1];        
        for(int i = 2;i<n;i++){
        	int X = coordinates[i][0] , Y = coordinates[i][1];
        	if((double)abs(X-X0)/abs(Y-Y0) != (double)abs(X-X1)/abs(Y-Y1))return false;
        }
    	return true;
    }
};