class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
    	int n = intervals.size();
    	int ret = n;
        for(int i = 0;i<n;i++){
        	for(int j = 0;j<n;j++){
        		if(i==j)continue;
        		if(intervals[i][0]>=intervals[j][0] && 
        		   intervals[i][1]<=intervals[j][1]){
        			ret--;
        			break;
        		}
        	}
        }
        return ret;
    }
};