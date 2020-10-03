class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int>cnt;
        map<pair<int,int>,bool>mark;
        int ret = 0;
        for(auto x : nums){
        	if(cnt.count(x-k) && !mark.count({x-k,x})){
        		ret++;
        		mark[{x-k,x}] = 1;
        	}
        	if(cnt.count(x+k) && !mark.count({x,x+k})){
        		ret++;
        		mark[{x,x+k}] = 1;
        	}

        	cnt[x] = 1;
        }
        return ret;
    }
   
};