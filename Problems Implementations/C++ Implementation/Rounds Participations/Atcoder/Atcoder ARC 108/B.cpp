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

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();

	string s;

	int n;

	cin>>n>>s;

	vector<char>stk;

	for(auto x : s){
		if(sz(stk)>=3){
			string wa = "";
			wa+=stk.back() , wa+=stk[sz(stk)-2] , wa+=stk[sz(stk)-3];
			reverse(all(wa));
			if(wa == "fox"){
				for(int i=0;i<3;i++)stk.pop_back();
			}
		}
		stk.push_back(x);
	}
	if(sz(stk)>=3){
			string wa = "";
			wa+=stk.back() , wa+=stk[sz(stk)-2] , wa+=stk[sz(stk)-3];
			reverse(all(wa));
			if(wa == "fox"){
				for(int i=0;i<3;i++)stk.pop_back();
			}
	}
	cout<<sz(stk)<<endl;
	
}