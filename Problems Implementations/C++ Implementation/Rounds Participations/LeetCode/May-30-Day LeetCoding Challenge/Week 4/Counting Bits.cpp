class Solution {
public:
    vector<int> countBits(int num) {
        	std::vector<int> ret(num+1);
        	for(int i=1;i<=num;i++){
        		if(i&1)ret[i] = ret[i/2]+1;
        		else   ret[i] = ret[i/2];
        	}
        	return ret;
    }
};