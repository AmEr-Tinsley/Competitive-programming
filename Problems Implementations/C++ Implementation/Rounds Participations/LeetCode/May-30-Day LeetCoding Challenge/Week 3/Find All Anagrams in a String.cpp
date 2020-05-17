class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        	std::vector<int> freq(26);
        	for(auto c : p)freq[c-'a']++;
        	int l = 0;
        	std::vector<int> ret,freq2(26);
        	for(int i=0;i<s.size();i++){
        		freq2[s[i]-'a']++;
        		while(check(freq2,freq))freq2[s[l]-'a']--,l++;
        		bool ok = true;
        		for(int j=0;j<26;j++)if(freq[j]!=freq2[j])ok=false;
        		if(ok)ret.push_back(l);
        	}
        	return ret;
    }
    bool check(std::vector<int> &a,std::vector<int> &b){
    	for(int i=0;i<26;i++)if(a[i]>b[i])return true;
    	return false;
    }
};