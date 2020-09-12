class Solution {
public:
	std::vector<vector<int>> ans;
	int K;
    vector<vector<int>> combinationSum3(int k, int n) {
    	K = k;
        vector<int> v;
        go(0,1,n,v);
        return ans;
    }
    void go(int indx,int curr_val,int rem_n,vector<int>&curr){
    	if(rem_n == 0){
    		if(curr.size()==K)
    		ans.push_back(curr);
    		return;
    	}
    	if(indx == K || curr_val>9 || curr_val>rem_n)return;

    	if(rem_n >= curr_val){
    		curr.push_back(curr_val);
    		go(indx+1,curr_val+1,rem_n-curr_val,curr);
    		curr.pop_back();
    	}
    	go(indx,curr_val+1,rem_n,curr);
    }
};