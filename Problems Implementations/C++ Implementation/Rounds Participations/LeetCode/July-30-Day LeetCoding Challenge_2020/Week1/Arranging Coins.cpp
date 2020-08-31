class Solution {
public:
    int arrangeCoins(int n) {
        int l = 0 , r = n,ret;

        while(l<=r){
        	int mid = (l+r)/2;
        	if((ll)mid*(mid+1)/2 <= n ){
        		l = mid + 1;
        		ret = mid;
        	}
        	else	r = mid-1;
        }
        return ret;
    }
};