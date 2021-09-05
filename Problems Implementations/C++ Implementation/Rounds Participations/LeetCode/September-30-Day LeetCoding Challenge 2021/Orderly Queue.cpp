class Solution {
public:
    string orderlyQueue(string a, int k) {
    	
    	int n = a.size();
    	string ans = a;
    	if(k>1){
    		sort(a.begin(),a.end());
    		return a;
    	}
    	for(int i = 0;i<n;i++){
    		char x = a[i];
    		a.push_back(x);
    		if(ans>a.substr(i+1,n)){
    			ans = a.substr(i+1,n);
    		}
    	}

    	return ans;
    }
};