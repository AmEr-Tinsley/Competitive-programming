#include <bits/stdc++.h>
 
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define ll long long
 
using namespace std;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	
	string a;
 
	cin>>a;
	reverse(all(a));
	std::vector<int> occ(2020);
	ll curr = 0;
	ll pw = 1;
	ll ans = 0;
	occ[0]=1;
	for(int i=0;i<sz(a);i++){
		curr = pw*(a[i]-'0')+curr;
		curr%=2019;
		pw*=10;
		pw%=2019;
		ans+=occ[curr];
		occ[curr]++;
	}
	cout<<ans<<endl;
}