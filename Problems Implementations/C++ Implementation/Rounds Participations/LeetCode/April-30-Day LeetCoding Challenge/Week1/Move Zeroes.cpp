class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int curr = 0;
        int n = (int)nums.size();
        int zeros = 0;
        for(int i=0;i<n;i++){
        	if(nums[i]!=0)nums[curr++]=nums[i];
        	else	zeros++;
        }
        for(int i=n-zeoros;i<n;i++)nums[i]=0;
    }
};