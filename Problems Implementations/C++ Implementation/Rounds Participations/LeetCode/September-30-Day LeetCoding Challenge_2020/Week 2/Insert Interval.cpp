class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ret;
        if(intervals.size()== 0)return {newInterval};
        int l = min(newInterval[0],intervals[0][0]) , 
        	r = min(newInterval[1],intervals[0][1]);
        bool done = (newInterval[0] == l && newInterval[1] == r);
        for(int i = 0 ;i<intervals.size();i++){
        	if(intervals[i][0]>r){
        		ret.push_back({l,r});
        		l = intervals[i][0];
        		r = intervals[i][1];
        		if(!done){
        			if(l>newInterval[0]){
        				l = newInterval[0];
        				if(r>newInterval[1]){
        					ret.push_back(newInterval);
        					i--;
        				}
        				done = true;
        			}
        		}
        	}
        	else{
        		r = max(r,intervals[i][1]);
        	}
        	if(newInterval[0]>= l  && newInterval[0]<=r){
        		r = max(r,newInterval[1]);
        		done = true;
        	}
        }
        ret.push_back({l,r});
        if(newInterval[0]>r)ret.push_back(newInterval);
        return ret;
    }
};