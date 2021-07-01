class Solution {
public:
    vector<int> grayCode(int n) {
        
        std::vector<string> seq;
        seq.push_back("0");seq.push_back("1");
        for(int i =2;i<(1<<n);i*=2){
        	for(int j = i-1;j>=0;j--)seq.push_back(seq[j]);
        	for(int j=0;j<i;j++)seq[j] = "0"+seq[j];
        	for(int j = i;j<seq.size();j++)seq[j] = "1"+seq[j];
        }

    	return binaryStringsToDecimal(seq);

    }

    vector<int> binaryStringsToDecimal(vector<string> &a){
    	std::vector<int> result;
    	for(auto x: a){
    		int curr = 0;
    		int cnt = 1;
    		while(x.size()){
    			curr+= (x.back()-'0')*cnt;
    			cnt*=2;
    			x.pop_back();
    		}
    		result.push_back(curr);
    	}
    	return result;
    }
};