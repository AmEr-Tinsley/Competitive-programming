class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        	vector<vector<int>>ret;

        	int i = 0 , j = 0;
        	while(i<A.size() && j<B.size()){
        		if(A[i][0]>B[j][1])j++;
        		else if(A[i][1] < B[j][0])i++;
        		else{
        			ret.push_back({max(A[i][0],B[j][0]),min(A[i][1],B[j][1])});
        			A[i][1] < B[j][1] ? i++ : j++;
        		}
        	}
        	return ret;
    }
};