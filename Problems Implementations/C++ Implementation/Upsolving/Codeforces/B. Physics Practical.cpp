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
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n;
	scanf("%d",&n);
	std::vector<int> pref(10001);
	for(int i = 0;i<n;i++){
		int x;
		scanf("%d",&x);
		pref[x]++;
	}
	int ans = n;
	for(int i = 1;i<=10000;i++){
		pref[i]+=pref[i-1];
		if(i%2 == 0)ans = min(ans,n-pref[i]+pref[i/2-1]);
	}
	
	printf("%d\n",ans );
	
}