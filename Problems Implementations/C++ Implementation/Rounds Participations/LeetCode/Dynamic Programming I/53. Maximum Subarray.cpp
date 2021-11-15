class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mn = 2e9;
        int curr = 0;
        int ans = -2e9;
        for(int i = 0;i<n;i++){
            curr+= nums[i];
            ans = max(ans,max(curr,curr - mn));
            mn = min(mn,curr);
        }
        return ans;
    }
};