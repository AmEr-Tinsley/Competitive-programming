#include <bits/stdc++.h>
 
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(),(a).end()
#define ll long long
 
using namespace std;
 
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
 
const int N=2e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;
 
char a[105];
void solve(){
	scanf("%s",a);
	int curr = 0;
	int n = strlen(a);
	int zeros = 0;
	int ones = 0;
	for(int i=0;i<n;i++){
		if(a[i]=='0')zeros++;
		else ones++;
	}
	if(!zeros || !ones){
		printf("%s\n",a);
		return;
	}
	printf("%c",a[0]);
	for(int i=1;i<n;i++){
		if(a[i-1]==a[i]){
			if(a[i]=='0')
				printf("1");
			else	printf("0");
		}
		printf("%c",a[i] );
	}
	printf("\n");
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	
	scanf("%d",&tc);
 
	while(tc--){
		solve();
	}
}