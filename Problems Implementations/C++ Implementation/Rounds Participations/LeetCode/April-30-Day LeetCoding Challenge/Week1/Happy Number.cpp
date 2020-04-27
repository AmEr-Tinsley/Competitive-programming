class Solution {
public:
    bool isHappy(int n) {
    		std::vector<bool> seen(100000);
    		while(n!=1){
	        	int tmp = 0;
	        	while(n){
	        		tmp+=((n%10)*(n%10));
	        		n/=10;
	        	}
	        	n = tmp;
	        	if(seen[n])break;
	        	seen[n]=1;
        	}
        	return (n==1);
    }
};