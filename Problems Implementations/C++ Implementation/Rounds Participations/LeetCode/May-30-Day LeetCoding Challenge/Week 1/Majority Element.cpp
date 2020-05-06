class Solution {
public:
    int majorityElement(vector<int>& nums){
        	map<int,int>occ;
            int n = nums.size();
        	for(auto x : nums)occ[x]++;
        	for(auto p : occ)if(p.second>n/2)return p.first;
            return -1;
    }	
};