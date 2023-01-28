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
	map<int,bool>occ;
	for(int i=0,x;i<n;i++){
		scanf("%d",&x);
		occ[x] = 1;
	}
	scanf("%d",&n);
	for(int i=0,x;i<n;i++){
		scanf("%d",&x);
		if(occ.count(10000-x))return !printf("YES\n");
	}
	printf("NO\n");
}