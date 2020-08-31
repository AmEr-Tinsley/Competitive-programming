class Solution {
public:
    string getPermutation(int n, int k) {
        string ret;
        for(int i=1;i<=n;i++)ret.push_back(char('0'+i));
        for(int i=1;i<k;i++){
        	next_permutation(ret.begin(),ret.end());
        }
        return ret;
    }
};