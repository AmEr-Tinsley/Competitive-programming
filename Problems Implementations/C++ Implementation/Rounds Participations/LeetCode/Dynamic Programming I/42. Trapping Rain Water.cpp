class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pref(n);
        for(int i = 0;i<n;i++){
            pref[i] = height[i];
            if(i){
                pref[i] = max(pref[i],pref[i-1]);
            }
        }
        int ans = 0;
        int mx=height[n-1];
        for(int i = n-2;i>=1;i--){
            mx = max(height[i],mx);
            ans+=(min(mx,pref[i]) - height[i]);
        }
        return ans;
    }
};