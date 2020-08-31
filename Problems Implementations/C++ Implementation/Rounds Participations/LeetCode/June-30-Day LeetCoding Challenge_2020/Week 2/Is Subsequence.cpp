class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i = 0;
        for(auto x : t)if(x==s[i])i++;
        return i==s.size();
    }
};