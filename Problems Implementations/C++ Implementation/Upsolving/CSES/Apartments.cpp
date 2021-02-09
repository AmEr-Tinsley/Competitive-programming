#include <bits/stdc++.h>
 
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
using namespace std;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=2e5+5,M=2e6+5,MOD=998244353,OO=1e9;
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
 	
 	int n,m,k;
 	scanf("%d %d %d",&n,&m,&k);
 	std::vector<int> a(n);
 	for(int i = 0;i<n;i++){
 		scanf("%d",&a[i]);
 	}
 	sort(all(a));
 	multiset<int>s;
 	for(int i = 0,x;i<m;i++)scanf("%d",&x),s.insert(x);
 	int ans = 0;
 	for(int i = 0;i<n;i++){
 		auto it = s.lower_bound(a[i]-k);
 		if(it!=s.end() && *it <= a[i]+k){
 			s.erase(it);
 			ans++;
 		}
 	}
 	printf("%d\n",ans );
}