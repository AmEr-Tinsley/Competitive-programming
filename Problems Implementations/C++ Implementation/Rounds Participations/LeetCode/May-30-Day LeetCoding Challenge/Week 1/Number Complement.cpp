class Solution {
public:
    int findComplement(int num) {
    	int ret = 0;
        for(int i=0;i<31;i++){
        	if((1<<i)>num)break;
        	if(!((1<<i)&num))ret+=(1<<i);
        }
        return ret;
    }
};