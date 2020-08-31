class Solution {
public:
	long long hash(string x){
		std::vector<int> occ(26);
		for(auto c : x)occ[c-'a']++;
		const int p = 31;
    	const int m = 1e9 + 9;
    	long long hash_value = 0,pw=1;
    	for(int i=0;i<26;i++){
    		hash_value = (hash_value + (i+1)*pw*occ[i])%m;
    		pw = (pw*p)%m;
    	}
    	return hash_value;
	}
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        	std::vector<std::vector<string>> ans;
        	map<long long,vector<int>>wa;
        	for(auto x : a){
        		wa[hash(x)].push_back(x);
        	}
        	for(auto p : wa)ans.push_back(p.second);
        	return ans;
    }	
};