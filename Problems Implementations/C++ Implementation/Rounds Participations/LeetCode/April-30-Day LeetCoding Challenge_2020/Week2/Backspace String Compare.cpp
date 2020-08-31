class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string a,b;
        for(auto x : S){
        	if(x=='#'){
        		if((int)a.size())a.pop_back();
        	}
        	else	a.push_back(x);
        }
        for(auto x : T){
        	if(x=='#'){
        		if((int)b.size())b.pop_back();
        	}
        	else	b.push_back(x);
        }
        return (a==b);
    }
};