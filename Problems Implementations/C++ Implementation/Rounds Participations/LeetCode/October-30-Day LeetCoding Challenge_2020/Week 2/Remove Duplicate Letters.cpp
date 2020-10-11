class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool>used(26);
        std::vector<int> cnt(26);
        string ret;
        for(auto x : s)cnt[x-'a']++;
        for(auto x : s){
        	if(!used[x-'a']){
        		while(ret.size() && ret.back() > x  && cnt[ret.back()-'a']>0){
        			used[ret.back()-'a'] = 0;
        			ret.pop_back();
        		}
        		ret.push_back(x);
        		used[x-'a'] = 1;
        	}
        	cnt[x-'a']--;
        }
        return ret;
    }
};