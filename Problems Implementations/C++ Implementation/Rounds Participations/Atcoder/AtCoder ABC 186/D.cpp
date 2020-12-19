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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	int n;
	scanf("%d",&n);
	ll ans = 0;
	int x ;
	std::vector<int> a(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(all(a));
	for (int i=n-1; i>=0; i--){
		ans += (ll)i*a[i] - (ll)(n-1-i)*a[i]; 
	} 
        
	printf("%lld\n",ans );
}