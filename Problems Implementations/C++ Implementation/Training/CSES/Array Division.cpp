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
 
 //typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9+7;
const ll INF = 2e18;
 
void solve(int tc ){
	int n,k;
 
	scanf("%d %d",&n,&k);
	std::vector<int> a(n);
	for(int i = 0;i<n;i++)scanf("%d",&a[i]);
	ll l = 0,r = 1e15;
	ll ans = 1e15;
	while(l<=r){
		ll mid = (l+r)/2;
 
		int how_many_subarrays = 1;
		ll curr = 0;
		for(int i = 0;i<n;i++){
			if(curr + a[i] <= mid){
				curr+=a[i];
			}else{
				how_many_subarrays++;
				curr = a[i];
				if(curr>mid){
					how_many_subarrays = k + 1;
				}
			}
		}
		if(how_many_subarrays<=k){
			ans = min(ans,mid);
			r = mid-1;
		}
		else	l = mid +1;
	}
	printf("%lld\n",ans ); 
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
 	 
 	 int tc = 1;
 	//scanf("%d",&tc);
 	for(int i = 1;i<=tc;i++)
 		solve(i);
}