#include <bits/stdc++.h>
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
using namespace std;
void file(){
	#ifndef ONLINE_JUDGE
    	freopen("tst.txt", "r", stdin);
	#endif	
}
const int N=1e5+5,MAX=3e7,MOD=1e9+7;
int tc;
 void solve(){
 	int n;
 	scanf("%d",&n);

 	std::vector<int> a(n);

 	for(int i=0;i<n;i++)scanf("%d",&a[i]);

 	int ans =  0;

 	for(int i=0;i<n;i++){
 		for(int j=i+1;j<n;j++){
 			int m = a[i]*a[j];
 			int curr = 0;
 			while(m)curr+=m%10,m/=10;
 			ans=max(ans,curr);
 		}
 	}

 	printf("%d\n",ans );

 }

int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	file();
	
	scanf("%d",&tc);

	while(tc--)solve();
}