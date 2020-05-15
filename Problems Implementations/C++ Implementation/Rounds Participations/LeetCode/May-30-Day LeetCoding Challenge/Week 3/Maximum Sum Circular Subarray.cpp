class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        	long long pref = 0;
        	set<pair<long long,int>>s;
        	int n = A.size();
        	s.insert({0,-1});
        	int ret = -1e9;
        	for(int i = 0; i < 2*n ;i++){
        		pref+=A[i%n];
        		while(i - (*s.begin()).second > n)s.erase(s.begin());
        		ret = max((long long)ret,pref-(*s.begin()).first);
        		s.insert({pref,i});
        	}
        	return ret;
    }
};