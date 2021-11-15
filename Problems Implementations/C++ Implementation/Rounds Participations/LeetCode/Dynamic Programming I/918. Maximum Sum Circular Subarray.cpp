class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)nums.push_back(nums[i]);
        n*=2;
        vector<int>pref(2*n+1);
        int ans = -2e9;
        multiset<int>s;
        s.insert(0);
        for(int i = 1;i<=n;i++){
            pref[i] = nums[i-1] + pref[i-1];
            int mn = *s.begin();            
            ans = max(ans,pref[i] - mn);
            s.insert(pref[i]);
            if(s.size() > n/2){
                auto it = s.lower_bound(pref[i-n/2]);
                s.erase(it);
            }
        }
        return ans;
    }
};