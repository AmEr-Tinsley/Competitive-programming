class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l = 0 , p = 1,n = nums.size(),ret = 0;

        for(int r = 0;r < n;r++){
        	p*=nums[r];
        	while(l<=r && p >= k)p/=nums[l++];
        	ret+=r-l+1;
        }
        return ret;
    }
};