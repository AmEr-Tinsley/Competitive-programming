class Solution {
public:
	std::vector<int> wa;
    Solution(vector<int>& w) {
    	wa = w;
        for(int i=1;i<wa.size();i++)wa[i]+=wa[i-1];
    }
    
    int pickIndex() {
        return upper_bound(wa.begin(),wa.end(),rand()%wa.back()) - wa.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */