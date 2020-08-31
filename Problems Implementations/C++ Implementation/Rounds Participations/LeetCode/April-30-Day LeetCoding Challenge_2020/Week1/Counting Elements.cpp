class Solution {
public:
    int countElements(vector<int>& arr) {
        	std::vector<int> occ(1001);
        	for(auto x : arr)occ[x]++;
        	int ret = 0;
        	for(int i=0;i<1000;i++){
        		if(occ[i+1])ret+=occ[i];
        	}
        	return ret;
    }
};