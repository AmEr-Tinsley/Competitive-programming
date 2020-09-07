class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string>v = split(str);
        if(v.size() != pattern.size())return false;
        map<string,char> matchstr;
        map<char,string> matchchar;
        for(int i = 0;i<v.size();i++){
        	if(!matchstr.count(v[i])){
        		matchstr[v[i]] = pattern[i];
        	}
        	if(!matchchar.count(pattern[i])){
        		matchchar[pattern[i]] = v[i];
        	}
        	if(matchchar[pattern[i]] != v[i])return false;
        	if(matchstr[v[i]]!= pattern[i])return false;
        }
        return true;
    }
	vector<string> split(string &a){
		vector<string>v;
		string curr ="";
		for(auto x : a){
        	if(x == ' ')v.push_back(curr),curr="";
        	else	curr+=x;
        }
        if(curr.size())v.push_back(curr);
        return v;
	}
};