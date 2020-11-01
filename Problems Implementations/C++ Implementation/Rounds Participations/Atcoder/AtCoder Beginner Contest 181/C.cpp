//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
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
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9;

bool check(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){

	if((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) ))return false;
	return true;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
 	
 	int n;

 	scanf("%d",&n);

 	std::vector<pair<ll,ll>> a(n);

 	for(int i =0;i<n;i++){
 		scanf("%lld %lld",&a[i].first,&a[i].second);
 	}

 	for(int i = 0;i<n;i++){
 		for(int j=i+1;j<n-1;j++){
 			for(int k = j+1;k<n;k++){
 				if(check(a[i].first,a[i].second,a[j].first,a[j].second,a[k].first,a[k].second)){
 					return !printf("Yes\n");
 				}
 			}
 		}
 	}

 	printf("No\n");

	
}