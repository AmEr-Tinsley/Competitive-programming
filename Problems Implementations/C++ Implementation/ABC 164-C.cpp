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
 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();
	
	int n;
 
	cin>>n;
	string a;
	set<string>s;
	for(int i=0;i<n;i++)cin>>a,s.insert(a);
	cout<<sz(s)<<endl;
}