class Solution {
public:
	vector<int>first_half , second_half;
	vector<vector<vector<int>>> sum;
	vector<vector<int>> ans;
	int trgt;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum.resize(501);
        trgt = target;
        divide_candidates(candidates);
        vector<int>v;
        go_first_half(0,v,0);
        go_second_half(0,v,0);
        
        return ans;
    }
    
    void divide_candidates(vector<int>&candidates){
    	int n = candidates.size();
    	for(int i = 0;i<n;i++){
        	if(i<n/2)first_half.push_back(candidates[i]);
        	else	second_half.push_back(candidates[i]);
        }
    }

    void go_first_half(int indx,vector<int>&curr,int s){
    	if(indx == first_half.size()){
    		sum[s].push_back(curr);
    		return;
    	}
    	for(int take = 0;;take++){
    		if(s+take*first_half[indx]>trgt)break;
    		if(take)curr.push_back(first_half[indx]);
    		go_first_half(indx+1,curr,s+take*first_half[indx]);
    	}
    	//backtrack
    	for(int take = 1;;take++){
    		if(s+take*first_half[indx]>trgt)break;
    		curr.pop_back();
    	} 
    }

    void go_second_half(int indx,vector<int>&curr,int s){
    	if(indx == second_half.size()){
    		for(int i = 0;i<sum[trgt-s].size();i++){
    			combine(sum[trgt-s][i],curr);
    		}
    		return;
    	}

    	for(int take = 0;;take++){
    		if(s+take*second_half[indx]>trgt)break;
    		if(take)curr.push_back(second_half[indx]);
    		go_second_half(indx+1,curr,s+take*second_half[indx]);
    	}
    	//backtrack
    	for(int take = 1;;take++){
    		if(s+take*second_half[indx]>trgt)break;
    		curr.pop_back();
    	}
    }

    void combine(vector<int>&a,vector<int>&b){
    	vector<int> ret;
    	for(auto x : a)ret.push_back(x);
    	for(auto x : b)ret.push_back(x);
    	ans.push_back(ret);
    }
};