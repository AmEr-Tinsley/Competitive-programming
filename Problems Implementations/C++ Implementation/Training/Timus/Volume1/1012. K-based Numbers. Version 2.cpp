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

int n,k;
double memo[2000][2];
double solve(int indx,int yes){
	if(indx == n)return 1;
	double &ret = memo[indx][yes];
	if(ret != -1.0)return ret;
	ret = 0;
	for(int i = (yes==1) ;i<k;i++){
		ret+=solve(indx+1,(i==0));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

	cin>>n>>k;
	for(int i = 0;i<n;i++)memo[i][0] = memo[i][1] = -1;
	cout<<solve(0,1)<<endl;
}