class Solution {
public:
    int singleNumber(vector<int>& nums) {
        	for(int i = 1;i<(int)nums.size();i++){
        		nums[0]^=nums[i];
        	}
        	return nums[0];
    }
};