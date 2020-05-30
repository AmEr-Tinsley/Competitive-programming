class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<int,vector<int>>>v;

        for(auto p : points){
        	v.push_back({p[0]*p[0]+p[1]*p[1],p});
        }
        sort(v.begin(),v.end());
        std::vector<std::vector<int>> ret;
        for(int i=0;i<K;i++)ret.push_back(v[i].second);
        return ret;
    }
};