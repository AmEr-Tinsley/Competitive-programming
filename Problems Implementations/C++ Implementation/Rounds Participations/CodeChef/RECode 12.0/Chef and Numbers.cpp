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
	std::vector<int> a(n);

	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	int mx = 0;
	int ans;
	for(int i=1;i<=1000;i++){
		int curr = 0;
		for(int j=0;j<n;j++){
			if(a[j]==i){
				curr++;
				if(a[j+1]==i)j++;
			}
		}
		if(curr>mx){
			mx = curr;
			ans = i;
		}
	}
	printf("%d\n",ans );
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	file();
	scanf("%d",&tc);

	while(tc--)solve();
}