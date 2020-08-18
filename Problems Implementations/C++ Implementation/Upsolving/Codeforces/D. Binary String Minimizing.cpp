//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
 
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
int tc;
const int N=1e6+5,MOD=1e9+7;
 
void solve(){
	int n;
	ll k;
	string a;
 
	cin>>n>>k>>a;
 
	queue<int>q;
	for(int i=0;i<sz(a);i++){
		if(a[i]=='0'){
			while(sz(q)&& i-q.front()>k)q.pop();
			if(sz(q))a[q.front()]='0',a[i]='1',k-=(i-q.front()),q.pop(),q.push(i);
		}
		else{
			q.push(i);
		}
	}
	cout<<a<<"\n";
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();
 
 	cin>>tc;
 
 	while(tc--)solve();
 	
	
}