class RecentCounter {
public:
	std::vector<int> history;
    RecentCounter() {
        history = std::vector<int>(0);
    }
    
    int ping(int t) {
        history.push_back(t);
        return history.end() - lower_bound(history.begin(),history.end(),t-3000);
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */