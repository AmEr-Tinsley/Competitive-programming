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
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

	int n,m;

	scanf("%d %d",&n,&m);

	std::vector<int> a(n);

	for(auto &x : a)scanf("%d",&x);
	sort(all(a));

	for(int i = 0,x;i<m;i++){
		scanf("%d",&x);
		int l = 0 , r = n-1 , ans = n;

		while(l<=r){
			int mid = (l+r)/2;
			if(a[mid]>x)r=mid-1,ans = mid;
			else	l = mid+1;
		}
		printf("%d ",ans );
	}
	
}