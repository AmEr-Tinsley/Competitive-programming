class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    		long long pref = 0;
    		long long mn = 0;
    		long long ans = -1e18;
        	for(auto x : nums){
        		pref+=x;
        		ans = max(ans,pref-mn);
        		mn = min(mn,pref);
        	}
        	return ans;	
    }
};