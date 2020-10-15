class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>ret;
        int n = nums.size();
        k%=n;

        for(int i = n-k;i<n;i++)ret.push_back(nums[i]);
        for(int i = 0;i<n-k;i++)ret.push_back(nums[i]);
        for(int i = 0;i<n;i++)nums[i]=ret[i];
        return;
    }
};