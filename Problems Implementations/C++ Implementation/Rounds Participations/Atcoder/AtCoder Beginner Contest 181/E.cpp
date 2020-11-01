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
int a[N],b[N];
ll memo[N][2][2];
int n,m;
ll solve(int indx,int choseme,int matched){
	if(indx == n){
		if(matched)return 0;
		return 1000000000000000;
	}
	ll &ret = memo[indx][choseme][matched];
	if(~ret)return ret;
	ret = 0;
	if(choseme){
		ret = a[indx]-a[indx-1] + solve(indx+1,0,matched);
		return ret;
	}
	
	ret = solve(indx+1,1,matched);
	
	if(!matched){
		int  pos = lower_bound(b,b+m,a[indx]) - b;
		int diff;
		if(pos && pos!=m){
			diff = min(abs(a[indx]-b[pos-1]),abs(a[indx]-b[pos]));
		}
		if(!pos){
			diff = abs(a[indx]-b[0]);
		}
		if(pos == m)diff = abs(a[indx]-b[m-1]);
		ret = min(ret,diff+solve(indx+1,0,1));
	}

	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();

	scanf("%d %d",&n,&m);

	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	for(int j = 0;j<m;j++)scanf("%d",&b[j]);
	sort(a,a+n);
	sort(b,b+m);
 	memset(memo,-1,sizeof(memo));
	printf("%lld\n",solve(0,0,0));
}