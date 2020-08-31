class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum = 0 , n = nums.size();
        std::vector<bool> seen(n+1);
        for(auto x : nums){
        	if(seen[x])return x;
        	seen[x]=1;
        }
       	return -1;
    }
};