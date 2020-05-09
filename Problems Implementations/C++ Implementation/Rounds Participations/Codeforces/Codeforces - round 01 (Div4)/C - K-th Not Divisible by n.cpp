#include<bits/stdc++.h>
 
using namespace std;
 
bool check(int x){
	while(x>=10){
		if(x%10)return false;
		x/=10;
	}
	return true;
}
int main(){
 
	int tc;
 
	scanf("%d",&tc);
 
	while(tc--){
		int n,k;
		scanf("%d %d",&n,&k);
		long long ans = (long long )k/(n-1)*n + k - (long long )k/(n-1)*(n-1);
		if(ans%n == 0)ans--;
		printf("%lld\n",ans);
	}
 
}