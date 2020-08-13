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
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
int tc;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	int n,k;
	scanf("%d %d",&n,&k);
	std::vector<int> a(n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(all(a));
	if(k==0){
		if(a[0]==1)return !printf("-1\n");
		printf("%d\n",a[0]-1 );
	}
	else if(k==n){
		printf("%d\n",a.back());
	}
	else{
		if(a[k]==a[k-1])return !printf("-1\n");
		printf("%d\n",a[k-1]);
	}
}