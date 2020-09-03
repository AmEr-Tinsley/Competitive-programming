class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();

        for(int i =  0;i<n-1;i++){
        	if(n%(i+1) == 0){
        		string aux = s.substr(0,i+1);
        		int x = n/(i+1);
        		string S = "";
        		while(x--)S+=aux;
        		if(S==s)return true;
        	}
        }
        return false;
    }
};