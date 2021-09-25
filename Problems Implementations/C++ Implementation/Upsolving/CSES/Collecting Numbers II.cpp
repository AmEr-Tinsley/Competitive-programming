#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
//using namespace  __gnu_pbds;
 
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9+7;
const ll INF = 2e18;
 
 
void solve(int tc ){
	int n,m;
	scanf("%d %d",&n,&m);
	std::vector<int> pos(N);
	std::vector<int> a(n);
	for(int i = 0,x;i<n;i++)scanf("%d",&a[i]),pos[a[i]]=i;
	int ans = 1;
	int lst = -1;
	pos[n+1] = n;
	for(int i = 1;i<=n;i++){
		if(pos[i]<lst){
			ans++;
		}
		lst = pos[i];
	}
	for(int i  = 0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		int wa1 = a[x-1], wa2 = a[y-1];
		swap(a[x-1],a[y-1]);
		ans = ans - ((pos[wa1]>pos[wa1+1]) + (pos[wa1-1]>pos[wa1]));
		pos[wa1] = y-1;
		ans = ans + ((pos[wa1]>pos[wa1+1]) + (pos[wa1-1]>pos[wa1]));
		ans = ans - ((pos[wa2]>pos[wa2+1]) + (pos[wa2-1]>pos[wa2]));
		pos[wa2] = x-1;
		ans = ans + ((pos[wa2]>pos[wa2+1]) + (pos[wa2-1]>pos[wa2]));
		
		printf("%d\n",ans );
 
	}
 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 	 
 	 int tc = 1;
 	//scanf("%d",&tc);
 	for(int i = 1;i<=tc;i++)
 		solve(i);
}