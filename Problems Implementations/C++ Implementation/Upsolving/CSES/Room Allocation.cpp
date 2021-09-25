#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
using namespace  __gnu_pbds;
 
typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9+7;
const ll INF = 2e18;
 
bool cmp(pair<int,pair<int,int>>&p1 , pair<int,pair<int,int>>&p2){
 
	return p1.second.first<p2.second.first;
}
void solve(int tc ){
	int n;
 
	scanf("%d",&n);
 
	std::vector<pair<int,pair<int,int>>>a(n);
 
	for(int i = 0;i<n;i++)scanf("%d %d",&a[i].first,&a[i].second.first),a[i].second.second = i;
	sort(all(a),cmp);
	
	multiset<pair<int,int>>s;
	std::vector<int> ans(n);
	for(auto x : a){
		auto it =  s.lower_bound({x.first,-1});
 
		if(it == s.begin()){
			ans[x.second.second] = sz(s) + 1;
		}
		else{
			ans[x.second.second] = ans[(--it)->second];
			s.erase(it);
		}
		s.insert({x.second.first,x.second.second});
	}
	int mx = 0;
	for(auto x : ans)mx = max(mx,x);
	printf("%d\n",mx );
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