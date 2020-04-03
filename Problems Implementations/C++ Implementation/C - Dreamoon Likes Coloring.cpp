#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
int n,m;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	scanf("%d %d",&n,&m);
	std::vector<int> a(m+1),ans(m+1);
	ll wa = 0;
	for(int i=1;i<=m;i++)scanf("%d",&a[i]),wa+=a[i],ans[i]=i;
	if(wa<n)return !printf("-1\n");
	for(int i=1;i<=m;i++){
		if(n-a[i]+1 < i){
			return !printf("-1\n");
		}
	}
 
	int curr = n+1;
 
	for(int i=m;i>=1;i--){
		if(curr > a[i]+ans[i]){
			ans[i] = curr - a[i];
			curr = ans[i];
		}
		else break;
	}
 
 
	for(int i=1;i<=m;i++)printf("%d ",ans[i]);
	printf("\n");
}