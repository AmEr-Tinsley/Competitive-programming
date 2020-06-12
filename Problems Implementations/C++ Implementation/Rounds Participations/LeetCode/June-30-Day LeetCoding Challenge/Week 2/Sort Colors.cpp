class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::vector<int> freq(3);
        for(auto x : nums)freq[x]++;
        std::vector<int> ret;
        for(auto x : {0,1,2}){
        	while(freq[x]--)ret.push_back(x);
        }
        nums=ret;
    }
};