class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
    	if(points.size() == 0 ) return 0;
        sort(points.begin(),points.end());
        int l = points[0][0],r = points[0][1],ret = 1;
        for(auto p : points){
        	if(p[0]<=r){
        		l = max(l,p[0]);
        		r = min(r,p[1]);
        	}
        	else{
        		ret ++;
        		l = p[0] , r = p[1];
        	}
        }
        return ret;
    }
};