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

void solve(){
	string a;

	cin>>a;
	if(sz(a)<=2){
		cout<<"YES\n";
		return;
	}
	bool ok = true;
	for(int i=2;i<sz(a);i++){
		if(a[i]!=a[i-2])ok = false;
	}
	if(ok && ((a[0]==a[1]) || (sz(a)%2==0)))
		cout<<"YES\n";
	else	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	cin>>tc;

	while(tc--)solve();
}