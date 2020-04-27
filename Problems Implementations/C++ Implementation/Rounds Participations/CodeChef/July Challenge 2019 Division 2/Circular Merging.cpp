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
const int N=3e5+5,MAX=3e7,MOD=1e9+7;
 
int tc,n,x,q;

ll memo[805][805];
int a[805];
ll pre[805];
ll solve(int l,int r){
	if (l>=r)
		return 0;
	ll &ret=memo[l][r];
	if (~ret)
		return ret;
	ret=1e18;
	for(int i=l;i<r;i++)
		ret=min(ret,solve(l,i)+solve(i+1,r)+(pre[r]-pre[l-1]));
	return ret;
}

void solve(){
	
	ll ans=1e18;
    	memset(memo,-1,sizeof(memo));
    	pre[0]=0;
    	scanf("%d",&n);
    	for(int i=n+1;i<=2*n;i++)
    		scanf("%d",&a[i]),a[i-n]=a[i];
    	for(int i=1;i<=2*n;i++)
    		pre[i]=pre[i-1]+a[i];
    	for(int i=1;i<=n;i++)
    		ans=min(ans,solve(i,i+n-1));
    	printf("%lld\n",ans);
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();
    	scanf("%d",&tc);

    	while(tc--)solve();
    	

}