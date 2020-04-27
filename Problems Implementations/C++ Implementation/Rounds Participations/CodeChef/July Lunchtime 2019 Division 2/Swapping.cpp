#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
const int N=1e5+5,MAX=3e7,MOD=1e9+7;
int tc;
int a[N];
ll memo[N];
int n;
ll solve(int indx){
	if(indx<=0){
		return 0;
	}

	ll &ret = memo[indx];

	if(~ret)return ret;

	ret = max(solve(indx-2)+(ll)a[indx]*(indx-1)+(ll)a[indx-1]*indx,solve(indx-1)+(ll)a[indx]*indx);
	return ret;
}
void solve(){
 	scanf("%d",&n);

 	for(int i=0;i<=n;i++)memo[i]=-1;

 	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

 	printf("%lld\n",solve(n));
 }

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	file();
	
	scanf("%d",&tc);

	while(tc--)solve();
}