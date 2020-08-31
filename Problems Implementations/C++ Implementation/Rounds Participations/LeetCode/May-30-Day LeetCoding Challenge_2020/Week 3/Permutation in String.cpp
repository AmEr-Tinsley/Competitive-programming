class Solution {
public:
    bool checkInclusion(string s1, string s2){
        	std::vector<int> freq(26);
        	for(auto c : s1)freq[c-'a']++;
        	int l = 0;
        	std::vector<int> freq2(26);
        	for(int i=0;i<s2.size();i++){
        		freq2[s2[i]-'a']++;
        		while(check(freq2,freq))freq2[s2[l]-'a']--,l++;
        		bool ok = true;
        		for(int j=0;j<26;j++)if(freq[j]!=freq2[j])ok=false;
        		if(ok)return true;
        	}
        	return false;
    }
    bool check(std::vector<int> &a,std::vector<int> &b){
    	for(int i=0;i<26;i++)if(a[i]>b[i])return true;
    	return false;
    }
};