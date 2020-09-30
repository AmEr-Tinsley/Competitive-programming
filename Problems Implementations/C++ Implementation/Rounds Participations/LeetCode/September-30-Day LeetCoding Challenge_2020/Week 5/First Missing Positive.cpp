class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size() + 1;
        std::vector<bool> v(n+1);
        for(auto x : nums){
        	if(x> 0 && x <= n)v[x] = 1;
        }
        for(int i = 1;i<v.size();i++){
        	if(!v[i])return i;
        }
        return 0;
    }
};