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
    	freopen("test.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	int n;
	cin>>n;
	std::vector<int> occ(10000);
	int ans = 0;
	n/=2;
	int mx =1;
	for(int i=0;i<n;i++){
		mx*=10;
	}
	for(int i =0;i<mx;i++){
		int x = i , sum = 0;
		while(x){
			sum+=(x%10);
			x/=10;
		}
		occ[sum]++;
	}
	for(auto x : occ)ans+=x*x;

	cout<<ans<<"\n";

}