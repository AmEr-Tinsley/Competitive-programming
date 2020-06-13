class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	int who = -1 , mx = 0;
        std::vector<int> cnt(nums.size()),camefrom(nums.size(),-1);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
        	for(int j=0;j<i;j++){
        		if(nums[i]%nums[j] == 0){
        			if(cnt[i]<cnt[j]+1){
        				cnt[i] = cnt[j]+1;
        				camefrom[i] = j;
        			}
        		}
        	}
        	if(mx<cnt[i]){
        		mx=cnt[i];
        		who = i;
        	}
        }
        vector<int>ret;
        if(who == -1){
        	if(nums.size())ret.push_back(nums[0]);
        	return ret;
        }
        
        while(who!=-1){
        	ret.push_back(nums[who]);
        	who = camefrom[who];
        }
        return ret;
    }
};