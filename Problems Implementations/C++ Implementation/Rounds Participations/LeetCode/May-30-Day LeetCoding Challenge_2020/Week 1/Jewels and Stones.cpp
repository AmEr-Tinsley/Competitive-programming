class Solution {
public:
    int numJewelsInStones(string J, string S) {
        	std::vector<int> freq(500);

        	for(auto c : J)freq[c]++;
        	int ret= 0;
        	for(auto c : S)if(freq[c])ret++;
        	return ret;
    }
};