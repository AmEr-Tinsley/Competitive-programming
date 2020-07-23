//                             ¯\_(ツ)_/¯   
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mma,ava,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define ll long long
 
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

	int n,d;

	scanf("%d %d",&n,&d);
	std::vector<int> a(n);
	for(auto &x : a)scanf("%d",&x);
	ll ans = 0;
	for(int i = 0;i<n-2;i++){
		auto it = upper_bound(all(a),a[i]+d);
		it--;
		int j = it - a.begin();
		ll wa = j - i - 1;
		ans+=wa*(wa+1)/2;
	}
	printf("%lld\n",ans );
}