class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    	multiset<int>s;
    	if(nums.size() == 0 || k==0)return false;
    	s.insert(nums[0]);
    	for(int i = 1;i<nums.size();i++){
    		if(s.size() == k+1)s.erase(s.lower_bound(nums[i-k-1]));
    		auto it = s.lower_bound(nums[i]);
    		if(it == s.begin()){
    			if(check(*it,nums[i],t))return true;
    		}
    		else if(it == s.end()){
    			it--;
    			if(check(*it,nums[i],t))return true;
    		}
    		else{
    			if(check(*it,nums[i],t) || check(*(--it),nums[i],t))return true;
    		}
    		s.insert(nums[i]);
    	}
    	return false;
    }

    bool check(int a,int b,int t){
    	return (abs((long long)a-b)<=t);
    }
};