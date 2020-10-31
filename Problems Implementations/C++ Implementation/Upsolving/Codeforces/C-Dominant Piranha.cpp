//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_bac(X/j)
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
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9;

void solve(){
	int n;
	scanf("%d",&n);
	std::vector<int> a(n);
	set<int>s;
	int mx = 0 , ans = -1;
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
		mx = max(mx,a[i]);
	}

	for(int i = 0;i<n;i++){
		if(a[i]==mx){
			if(i && a[i]>a[i-1]){
				printf("%d\n",i+1 );
				return;
			}
			if(i != n-1 && a[i]>a[i+1]){
				printf("%d\n",i+1 );
				return;
			}
		}
	}
	printf("-1\n");
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 
	scanf("%d",&tc);

	while(tc--)solve();
}