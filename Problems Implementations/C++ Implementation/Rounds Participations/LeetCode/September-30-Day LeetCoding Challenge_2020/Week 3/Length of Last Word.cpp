class Solution {
public:
    int lengthOfLastWord(string s) {
        string curr = "";
        int ret =0;
        for(int i = 0;i<s.size();i++){
        	if(s[i] == ' '){
        		ret = curr.size();
        		curr = "";
        		while(s[i] == ' '){
        			i++;
        		}
        		i--;
        	}
        	else curr+=s[i];  	
        }
        return curr.size() == 0 ? ret : curr.size();
    }
};