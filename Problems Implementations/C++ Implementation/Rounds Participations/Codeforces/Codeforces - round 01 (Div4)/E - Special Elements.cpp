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
		int n;
		scanf("%d",&n);
		std::vector<int> a(n);
		std::vector<int> freq(n+1);
		std::vector<bool> done(n+1);
		for(int i=0;i<n;i++)scanf("%d",&a[i]),freq[a[i]]++;
		int ans = 0;
		for(int i=0;i<n;i++){
			int curr = a[i];
			for(int j=i+1;j<n;j++){
				curr+=a[j];
				if(curr>n)break;
				if(freq[curr]>0 && !done[curr])
					ans+=(freq[curr]),done[curr]=1;
			}
		}
		printf("%d\n",ans);
	}
 
}