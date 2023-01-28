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

	int n;
	string a;

	cin>>n>>a;
	map<char,int>occ;
	for(auto x : a)occ[x]++;
	for(int i = 0;i<n;i++){
		if(a[i]=='2' && occ[a[i]]>n/3){
			if(occ['0']<n/3)occ['0']++,occ['2']--,a[i]='0';
			else occ['1']++,occ['2']--,a[i]='1';
		}
		else if(a[i]=='1' && occ['1']>n/3 && occ['0']<n/3){
			occ['0']++,occ['1']--,a[i]='0';
		}
	}
	
	for(int i = n-1;i>=0;i--){
		if(a[i] == '0' && occ['0']>n/3){
			if(occ['2']<n/3)occ['2']++,occ['0']--,a[i]='2';
			else	occ['1']++,occ['0']--,a[i]='1';
		}
		else if(a[i] == '1' && occ['1']>n/3){
			occ['2']++,occ['1']--,a[i]='2';
		}
	}
	cout<<a<<endl;
}