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
	if(p1.first<p2.first)return true;
	else if(p1.first>p2.first)return false;
	return p1.second.first>p2.second.first;
}
void solve(int tc ){
	int n;
	scanf("%d",&n);
	std::vector<pair<int,pair<int,int>>>a(n) ;
	for(int i=0;i<n;i++)scanf("%d %d",&a[i].first,&a[i].second.first),a[i].second.second = i;
	sort(all(a),cmp);
	
	ordered_set s,s2;
	std::vector<int> ans1(n),ans2(n);
	s.insert(a.back().second.first);
	ans1[a.back().second.second] = 0;
 
	map<int,int>occ;
	occ[a.back().second.first] = 1;
	for(int i = n-2;i>=0;i--){
		int how_many = s.order_of_key(a[i].second.first) + occ[a[i].second.first];
		s.insert(a[i].second.first);
		ans1[a[i].second.second] = how_many;
		occ[a[i].second.first]++;
 
	}
 
	ans2[a[0].second.second] = 0;
	s2.insert(a[0].second.first);
	for(int i = 1;i<n;i++){
		int how_many = sz(s2) - s2.order_of_key(a[i].second.first);
		s2.insert(a[i].second.first);
		ans2[a[i].second.second] = how_many;
	}
	
	for(auto x : ans1)printf("%d ",x ? 1 : 0 );
	printf("\n");
	for(auto x : ans2)printf("%d ",x ? 1 : 0 );
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