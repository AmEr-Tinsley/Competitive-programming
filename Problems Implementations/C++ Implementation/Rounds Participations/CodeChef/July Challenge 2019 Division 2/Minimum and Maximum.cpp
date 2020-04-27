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
 
int tc,n,k;

char s[N];

int mod(char* num, int a){ 
    
    int res = 0; 
 
    for (int i = 0; num[i]; i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
    
    return res; 
} 

void solve(){
	scanf("%d %s",&n,s);
    	
    	int wa=mod(s,n);
    	
    	if (wa>=(n+1)/2)wa=n-wa;
    	
    	printf("%d\n",min(n-1,wa*2));
	
}
int main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
 	
    	scanf("%d",&tc);

    	while(tc--)solve();
    	

}