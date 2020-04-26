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
	int n,m;
 
	scanf("%d %d",&n,&m);
 
	std::vector<int> a(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
 
	for(int i = 200;i>=1;i--){
		int curr = 1;
		int cnt = 0;
		while(curr<=i){
			bool ok = false;
			for(int i=0;i<n;i++){
				if(a[i]==curr)ok = true;
			}
			cnt += (int)(!ok);
			curr++;
		}
		
		if(cnt<=m){
			printf("%d\n",i );
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	scanf("%d",&tc);
 
	while(tc--)solve();
}