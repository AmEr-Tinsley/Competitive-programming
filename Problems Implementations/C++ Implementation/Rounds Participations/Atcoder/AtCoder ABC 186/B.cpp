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
int a[105][105];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	int n,m;

	scanf("%d %d",&n,&m);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int ans = 1e9;
	for(int i = 0;i<=100;i++){
		int curr = 0;
		bool stop = false;
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				if(a[j][k] < i){
					curr = 1e9;
					stop = true;
					break;
				}
				else	curr += (a[j][k]-i);
			}
			if(stop)break;
		}
		ans = min(ans,curr);
	}

	printf("%d\n",ans );
}