class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int mx = values[0];
        int ans = 0;
        for(int i = 1;i<n;i++){
            mx--;
            ans = max(ans,mx+values[i]);
            mx = max(mx,values[i]);
        }
        return ans;
    }
};