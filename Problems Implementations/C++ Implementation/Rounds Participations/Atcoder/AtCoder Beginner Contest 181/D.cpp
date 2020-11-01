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

int memo[10][100];
string a;
int occ[10];
int to_int(string a){
	int ret = 0,curr = 1;
	while(sz(a)){
		ret+=(a.back()-'0')*curr;
		curr*=10;
		a.pop_back();
	}
	return ret;
}
int solve(int indx,string curr){
	if(sz(curr)>3)return 0;
	if(sz(curr) == 3){
		sort(all(curr));
		do{
			if(to_int(curr)%8 == 0)return true;
		}while(next_permutation(all(curr)));
		return 0;
	}
	if(indx == 10)return 0;
	int &ret = memo[indx][to_int(curr)];
	if(~ret)return ret;
	ret = 0;
	for(int i = 0;i<=min(occ[indx],3);i++){
		ret+=solve(indx+1,curr);	
		curr.pb(char(indx+'0'));	
	}
	return ret;

}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();

 	cin>>a;

 	if(sz(a)<3){
 		if(to_int(a)%8 == 0)return cout<<"Yes\n",0;
 		if(sz(a)==2){
 			swap(a[0],a[1]);
 			if(to_int(a)%8 == 0)return cout<<"Yes\n",0;
 		}
 		return cout<<"No\n",0;
 	}

 	for(auto x : a)occ[x-'0']++;
 	
 	memset(memo,-1,sizeof(memo));
 
 	if(solve(0,"")){
 		cout<<"Yes\n";
 	}
 	else	cout<<"No\n";
	
}