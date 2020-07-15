class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        string curr = "";
		for(int i = s.size()-1;i>=0;i--){
			if(s[i]==' ' && curr.size()){
				reverse(curr.begin(),curr.end());
				curr+=' ';
				ret+=curr;
				curr="";
			}
			else if(s[i] != ' ')curr+=s[i];
		}
		if(curr.size() && ret.size())reverse(curr.begin(),curr.end()),ret+=curr;
		else if(curr.size())reverse(curr.begin(),curr.end()),ret=curr;
		while(ret.size() && ret.back()==' ')ret.pop_back();
        return ret;
    }
};
