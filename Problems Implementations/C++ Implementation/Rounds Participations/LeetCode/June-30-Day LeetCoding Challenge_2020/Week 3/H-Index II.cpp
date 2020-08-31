class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(),l = 0,r = n-1;
        if(n==0)return 0;
        if(n==1){
        	if(citations[0]==0)return 0;
        	else	return 1;
        }
        while(l<=r){
        	int mid = (l+r)/2;
        	if(citations[mid] > n - mid) r = mid - 1;
        	else	l = mid+1; 
        }
        if(r < 0)return n; 
        if(citations[r] > n - r)return n;
        if(citations[r] == n-r)return citations[r];
        else	return n - r -1;
    }
};