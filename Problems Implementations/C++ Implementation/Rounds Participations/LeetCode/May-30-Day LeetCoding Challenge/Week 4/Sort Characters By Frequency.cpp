class Solution {
public:
    string frequencySort(string s) {
        std::vector<pair<int,int>> freq(300);
        for(int i=0;i<300;i++)freq[i].second = i;
        for(auto c : s)freq[c].first++;
        sort(freq.begin(),freq.end());
    	reverse(freq.begin(),freq.end());
    	string ret;
    	for(auto p : freq){
    		while(p.first--){
    			ret.push_back(char(p.second));
    		}
    	}
    	return ret;
    }
};