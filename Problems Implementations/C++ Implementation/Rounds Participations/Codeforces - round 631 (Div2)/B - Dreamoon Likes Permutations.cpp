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
 
void solve(){
	int n;
 
	scanf("%d",&n);
	std::vector<int> a(n),seen(n+1),pref(n+1),suff(n+1);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int cnt = 1;
	set<int>s;
	for(int i=0;i<n;i++){
		if(s.count(a[i]))break;
		s.insert(a[i]);
		while(s.count(cnt))cnt++;
		if(sz(s)==cnt-1)pref[i]=1;
	}
	cnt = 1;
	s.clear();
	for(int i=n-1;i>=0;i--){
		if(s.count(a[i]))break;
		s.insert(a[i]);
		while(s.count(cnt))cnt++;
		if(sz(s)==cnt-1)suff[i]=1;
	}
	std::vector<int> ans;
	for(int i=0;i<n-1;i++){
		if((pref[i] == 1) && (suff[i+1]==1))
			ans.pb(i+1);
	}
	printf("%d\n",sz(ans) );
	for(auto x : ans)printf("%d %d\n",x,n-x );
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	scanf("%d",&tc);
 
	while(tc--)solve();
}