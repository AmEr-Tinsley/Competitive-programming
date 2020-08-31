class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>pos;
        int pref = 0;
        pos[0] = -1;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
        		pref+= (nums[i] ? 1 : -1);
        		if(pos.count(pref))ans = max(ans,i-pos[pref]);
        		else	pos[pref]=i;
        }
        return ans;
    }
};