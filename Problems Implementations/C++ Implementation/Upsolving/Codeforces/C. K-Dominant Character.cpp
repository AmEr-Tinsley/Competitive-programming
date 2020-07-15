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
string a;
std::vector<int> pos[26];
int n;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	string a;

	cin>>a;
	n = sz(a);
	for(int i=0;i<n;i++)pos[a[i]-'a'].pb(i);
	int ans =1e9;
	for(int i = 0 ; i < 26 ; i++){
		pos[i].pb(n);
		int last = -1;
		int curr = 0;
		for(auto x : pos[i]){
			curr = max(curr,x-last);
			last = x;
		}
		ans = curr ? min(ans,curr) : ans;
	}
	cout<<ans<<"\n";
}