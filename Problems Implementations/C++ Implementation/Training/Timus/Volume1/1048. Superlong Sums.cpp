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
    	freopen("test.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

	int n;
	scanf("%d",&n);
	std::vector<int> v1,v2,ans;
	while(n--){
		int x,y;
		scanf("%d %d",&x,&y);
		v1.pb(x);
		v2.pb(y);
	}
	int wa = 0;
	for(int i = sz(v1) -1 ;i>=0;i--){
		int k = v1[i] + v2[i] + wa;
		if(wa)wa=0;
		if(k>=10){
			k-=10;
			wa = 1;
		}
		ans.pb(k);
	}
	reverse(all(ans));
	for(auto x : ans)printf("%d",x );
}