class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size() == 0 || matrix[0].size() == 0)return false;
        int i = get_row(matrix,target);
        return exist(matrix[i],target);
    }
    int get_row(vector<vector<int>> &matrix,int target){
    	int l = 0 , r = matrix.size() - 1 , ret = 0;
    	while(l<=r){
    		int mid = (l+r)/2;
    		if(matrix[mid].back() >= target){
    			ret = mid;
    			r = mid-1;
    		}
    		else	l = mid + 1;
    	}
    	return ret;
    }
    bool exist(vector<int>&row,int target){	
    	int l = 0 , r = row.size()-1;
    	while(l<=r){
    		int mid = (l+r)/2;
    		if(row[mid] == target)return true;
    		if(row[mid] > target)r = mid-1;
    		else	l = mid + 1;	
    	}
    	return false;
    }
};