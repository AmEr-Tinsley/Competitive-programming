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
    	freopen("test.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;

int n,memo[N];
int solve(int rem){
	if(rem == 0)return 0;
	int &ret = memo[rem];
	if(~ret)return ret;
	ret = 1e9;
	for(int i=1;i*i<=rem;i++){
		ret = min(ret,1+solve(rem-i*i));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	scanf("%d",&n);
	memset(memo,-1,sizeof(memo));
	printf("%d\n",solve(n) );
}