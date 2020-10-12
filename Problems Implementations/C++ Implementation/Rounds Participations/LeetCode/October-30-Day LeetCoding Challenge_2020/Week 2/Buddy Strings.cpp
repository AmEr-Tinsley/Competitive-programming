class Solution {
public:
    bool buddyStrings(string A, string B) {
    	if(A.size() != B.size())return false;
        vector<int>occ1(26),occ2(26);
        int n = A.size();
        vector<int>wa1,wa2;
        for(int i = 0;i<n;i++){
        	if(A[i]!=B[i])wa1.push_back(A[i]),wa2.push_back(B[i]);
        	occ1[A[i]-'a']++;
        	occ2[B[i]-'a']++;
        }
        if(wa1.size() > 2){
        	return false;
        }
        if(wa1.size() == 2){
        	if(wa1[0] == wa2[1] && wa1[1] == wa2[0])return true;
        	return false;
        }
        if(wa1.size() == 1)return false;
        for(int i = 0;i<26;i++){
        	if(occ1[i]>1 && occ2[i]>1)return true;
        }
        return false;
    }
};