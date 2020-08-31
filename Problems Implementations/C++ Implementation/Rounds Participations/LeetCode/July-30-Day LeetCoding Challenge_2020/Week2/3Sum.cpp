class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
  		int n = nums.size();
  		map<pair<int,int>,bool>ex;
  		sort(nums.begin(),nums.end());
  		map<int,vector<int>>wa;
  		vector<vector<int>>ret;
  		for(int i = 0;i<n;i++)wa[nums[i]].push_back(i);
  		for(int  i = 0; i<n ; i++){
  			for(int j = i+1;j<n;j++){
  				if(ex.count({nums[i],nums[j]}))continue;
  				std::vector<int> &v = wa[-nums[i]-nums[j]];
  				auto x = upper_bound(v.begin(),v.end(),j);
  				if(x != v.end()){
  					ex[{nums[i],nums[j]}] = true;
  					ret.push_back({nums[i],nums[j],-nums[i]-nums[j]});
  				}
  			}
  		}
  		return ret;
    }
};