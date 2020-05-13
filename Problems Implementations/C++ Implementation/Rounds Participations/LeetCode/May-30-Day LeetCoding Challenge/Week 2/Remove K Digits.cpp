class Solution {
public:
    string removeKdigits(string num, int k) {
    		string ret;
        	stack<char>stk;

        	for(auto c : num){
        		
        		while(stk.size() && stk.top()>c && k)stk.pop(),k--;
        		stk.push(c);
        	}
        	while(k)stk.pop(),k--;
        	while(stk.size())ret.push_back(stk.top()),stk.pop();
        	while(ret.size() && ret.back()=='0')ret.pop_back();
        	reverse(ret.begin(),ret.end());
        	if(ret.size()==0)ret= "0";
        	return ret;
    }
};