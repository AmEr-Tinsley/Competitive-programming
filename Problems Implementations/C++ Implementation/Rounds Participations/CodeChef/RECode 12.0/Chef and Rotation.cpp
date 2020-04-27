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

void solve(){
	int n;

	scanf("%d",&n);
	set<int>s;
	std::vector<int> a(n);
	map<int,vector<int>>pos;
	for(int i=0;i<n;i++)scanf("%d",&a[i]),pos[a[i]].pb(i);
	sort(all(a));
	int curr = 0;
	int ans = 1;
	int who = 0;
	for(int i=0;i<n;i++){
		if(a[i]==who)continue;
		who = a[i];
		auto x = lower_bound(all(pos[who]),curr);
		if(x == pos[who].end())ans++,curr=pos[who][0];
		else	curr = *x;
	}
	printf("%d\n",ans );
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	scanf("%d",&tc);

	while(tc--)solve();
}