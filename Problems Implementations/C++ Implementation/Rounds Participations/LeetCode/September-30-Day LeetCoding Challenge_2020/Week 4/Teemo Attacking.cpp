class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
     	int l = 0 , r = 0 , ret = 0;
     	for(auto x : timeSeries){
     		int lx = x , rx = x + duration - 1;

     		if(lx>r){
     			ret+=(r-l+1);
     			lx = x;
     			r = rx;
     		}
     		else{
     			r = max(rx , r);
     		}

     	}
     	ret+= (r-l+1);
     	return ret;
    }
};