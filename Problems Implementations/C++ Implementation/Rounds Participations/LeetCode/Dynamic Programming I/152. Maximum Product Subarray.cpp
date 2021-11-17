class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int mx = nums[0] , mn = nums[0];
        for(int i = 1;i<n;i++){
            int mxx = max(nums[i],max(nums[i]*mx,nums[i]*mn));
            int mnn = min(nums[i],min(nums[i]*mx,nums[i]*mn));
            mx = mxx;
            mn = mnn;
            ans = max(ans,mx);
        }
        return ans;
    }
};