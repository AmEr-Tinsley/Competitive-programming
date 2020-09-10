class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0 , cows = 0;
        int n = secret.size();
        map<char,int>occ;
        for(int i = 0;i<n;i++){
        	if(secret[i] == guess[i])bulls++;
        	else	occ[secret[i]]++;
        }
        for(int i = 0;i<n;i++){
        	if(secret[i]==guess[i])continue;
        	if(occ[guess[i]]>0)cows++,occ[guess[i]]--;
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }	
};