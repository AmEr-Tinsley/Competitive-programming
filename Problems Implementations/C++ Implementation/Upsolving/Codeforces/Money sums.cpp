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
    	//freopen("out.txt","w",stdout);
	#endif
}
int tc;
const int N=1e6+5,M=2e6+5,MOD=1e9+7,OO=1e9+7;
const ll INF = 2e18;
 
vector<vector<ll>>dp(N+1,vector<ll>(2));
 
void solve(int tc ){
   int n;
 
   scanf("%d",&n);
   
   bitset<100005>b;
   b[0] = 1;
   for(int i =0;i<n;i++){
	   int x;
	   scanf("%d",&x);
	   b = b | (b<<x);
   }
 
   vector<int>ans;
 
   for(int i = 1;i<=100000;i++){
	   if(b[i])ans.pb(i);
   }
   printf("%d\n",sz(ans));
   for(auto x : ans)printf("%d ",x);
   printf("\n");
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
    int tc = 1;
    //scanf("%d",&tc);
    for(int i = 1;i<=tc;i++)solve(i);
}