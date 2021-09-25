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
	int x,n;
	scanf("%d %d",&x,&n);
 
	set<int>lights;
	lights.insert(0);
	lights.insert(x);
	multiset<int>distances;
	distances.insert(x);
	for(int i = 0,y;i<n;i++){
		scanf("%d",&y);
		auto it  = lights.upper_bound(y);
		int lx = *(--it) , rx = *(++it) ;
		
		distances.erase(distances.lower_bound(rx-lx));
		distances.insert(y-lx);
		distances.insert(rx-y);
		lights.insert(y);
		printf("%d ",*(--distances.end()) );
	}
	printf("\n");
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 	 
 	 int tc = 1;
 	//scanf("%d",&tc);
 	for(int i = 1;i<=tc;i++)
 		solve(i);
}