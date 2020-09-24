class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int>occ1,occ2;
        for(auto c : s)occ1[c]++;
        for(auto c : t)occ2[c]++;
        for(auto c : t)if(occ1[c]!=occ2[c])return c;
        return '?';
    }
};