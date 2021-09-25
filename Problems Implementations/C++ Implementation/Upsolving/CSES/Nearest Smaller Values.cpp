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
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9+7;
const ll INF = 2e18;
 
bool cmp(pair<int,int>&p1,pair<int,int>&p2){
	if(p1.first < p2.first)return true;
	if(p1.first > p2.first)return false;
	return p1.second>p2.second;
}
 
void solve(int tc ){
	
	int n;
	scanf("%d",&n);
 
	std::vector<pair<int,int>>a(n);
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	
	sort(all(a),cmp);
	vector<int>ans(n);
	set<int>s;
	for(int i = 0;i<n;i++){
		auto it = s.lower_bound(a[i].second);
		if(it != s.begin()){
			ans[a[i].second] = *(--it) + 1;
		}
		s.insert(a[i].second); 
	}
 
	for(auto x : ans)printf("%d ",x );
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