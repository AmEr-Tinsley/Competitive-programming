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
const int N=3e5+5,MAX=3e7,MOD=1e9+7;
 
int tc,n;

void solve(){
	scanf("%d",&n);
    	vector<int>a(n);
    	double sum = 0;
    	for(int i=0;i<n;i++)scanf("%d",&a[i]),sum+=a[i];
    	double mean = sum/n;
    	int ans = -1;
    	int mn = 1e9+5;
    	for(int i=0;i<n;i++)if(((sum-a[i])/(n-1))==mean){ans=i+1;break;}

    	if(ans == -1)printf("Impossible\n");
    	else printf("%d\n",ans );
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	file();	
 	
    	scanf("%d",&tc);

    	while(tc--)solve();
    	

}