class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i=0;i<31;i++){
        	int cnt = 0;
        	for(auto x : nums)if(((1<<i) & abs(x)) != 0)cnt++;
        	if(cnt%3 == 1)ret|=(1<<i);
        }
        int cnt = 0;
        for(auto x : nums){
        	if(x==ret)cnt++;
        }

        return cnt==0 ? -ret : ret;
    }	
};