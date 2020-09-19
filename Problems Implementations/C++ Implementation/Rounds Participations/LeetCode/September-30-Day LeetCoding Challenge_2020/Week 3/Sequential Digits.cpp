class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    	set<int> s;
    	std::vector<int> ret;
        for(int mask = 1;mask<(1<<10);mask++){
        	long long curr = 0 , cnt = 1;
        	bool flag = false;
        	for(int i = 9;i>=0;i--){
        		if(mask & (1<<i)){
        			curr+=cnt*i;
        			cnt*=10;
        			flag = true;
        		}
        		else{
        			if(flag)break;
        		}
        	}
        	
        	if(curr>=low && curr<=high)s.insert(curr);
        }
        for(auto x : s)ret.push_back(x);
        
        return ret;
    }	
};