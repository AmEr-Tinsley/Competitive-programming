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
int n,ans = 1e9;
int get(int diff,int needed){
	return (diff != needed) ? (abs(needed - diff) == 1 ? needed-diff : 1e9 ) : 0; 
}
void wa(int needed,int &ret,vector<int>a){
	for(int i = 2;i<n;i++){
		int diff = a[i]-a[i-1];
		int gt = get(diff,needed);
		a[i]+=gt;
		ret+=abs(gt);
		if(gt>=1e9)return;
	}
}
void go(int x,int y,vector<int>a){
	int ret = abs(x)+abs(y);
	a[0]+=x,a[1]+=y;
	int needed = a[1]-a[0];
	wa(needed,ret,a);
	ans = min(ans,ret);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	scanf("%d",&n);
	std::vector<int> a(n);
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	for(auto x : {-1,0,1}){
		for(auto y : {-1,0,1}){
			go(x,y,a);
		}
	}
	if(ans>=1e9)printf("-1\n");	
	else	printf("%d\n",ans ); 
}
