//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
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
int tc;
const int N=1e6+5,MOD=1e9+7;
 
int n;
ll memo[N];
pair<int,int>a[N];
int wa[N];
int ans[N];
ll solve(int indx){
	if(indx==n)return 0;
 
	ll &ret = memo[indx];
 
	if(~ret)return ret;
	ret = 1e15;
	srand (time(NULL));
	for(int k=0;k<1;k++){
		int x = 500;
		
		for(int i=indx+2;i<=x+indx;i++){
			if(i>=n)break;
			if(ret>solve(i+1)+a[i].first-a[indx].first)
				ret = solve(i+1)+a[i].first-a[indx].first,wa[indx]=i;
		}
	}
	return ret;
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 	file();
 
 	scanf("%d",&n);
 
 	for(int i=0;i<n;i++)scanf("%d",&a[i].first),a[i].second=i;
 
 	sort(a,a+n);
 
 	memset(memo,-1,sizeof(memo));
 
 	printf("%lld ",solve(0));
 	int cnt = 1;
 	for(int i=0;i<n;i++){
 		for(int j=i;j<=wa[i];j++){
 			ans[a[j].second]=cnt;
 		}
 		cnt++;
 		i=wa[i];
 	}
 	printf("%d\n",cnt-1);
 
 	for(int i=0;i<n;i++)printf("%d ",ans[i]);
}