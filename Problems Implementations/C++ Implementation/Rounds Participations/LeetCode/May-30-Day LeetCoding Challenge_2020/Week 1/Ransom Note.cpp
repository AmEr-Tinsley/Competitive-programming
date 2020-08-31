class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        	std::vector<int> freqa(26) , freqb(26);
        	for(auto c : ransomNote)freqa[c-'a']++;
        	for(auto c : magazine)freqb[c-'a']++;

        	for(int i=0;i<26;i++){
        		if(freqa[i]){
        			if(freqa[i]>freqb[i])return false;
        		}
        	}
        	return true;
    }
};