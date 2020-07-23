//                             ¯\_(ツ)_/¯   
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mma,ava,tune=native")
//#pragma GCC optimize("unroll-loops")
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
int n,m,k;
int a[N];
bool check(int x){
	std::vector<int> rem(m,k);
	int curr = 0;
	for(int i = x;i<n;i++){
		if(rem[curr]>=a[i])rem[curr]-=a[i];
		else if(curr<m-1) rem[++curr]-=a[i];
		else	return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	scanf("%d %d %d",&n,&m,&k);

	for(int i=0;i<n;i++)scanf("%d",&a[i]);

	int l = 0 , r = n-1 ,ans;

	while(l<=r){
		int mid = (l+r)/2;
		if(check(mid))r=mid-1,ans = n-mid;
		else	l = mid+1;
	}
	printf("%d\n", ans);
}