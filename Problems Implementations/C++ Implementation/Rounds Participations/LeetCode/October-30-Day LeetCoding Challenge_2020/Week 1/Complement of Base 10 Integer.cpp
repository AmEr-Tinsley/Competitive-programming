class Solution {
public:
    int bitwiseComplement(int N) {
    	if(N == 0)return 1;
        int ret = 0;
        bool start = false;
        for(int i  = 30;i>=0;i--){
        	if((1<<i)&N){
        		start = true;
        	}
        	else if(start)ret+=(1<<i);
        }
        return ret;
    }
};