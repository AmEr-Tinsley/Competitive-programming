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

	int n,x,y;

	scanf("%d %d %d",&n,&x,&y);

	if(x>y)return !printf("%d\n", n);
	multiset<int>s;
	for(int i = 0,x;i<n;i++){
		scanf("%d",&x);
		s.insert(x);
	}
	int turn = 0 , ans = 0;
	while(sz(s)){
		if(turn){
			auto it = s.begin();
			int c = *it;
			s.erase(it);
			if( c+y <= x )s.insert(c+y);
		}
		else{
			auto it = s.begin();
			int c = *it;
			s.erase(it);
			if( c - x <= 0)ans++;
			else	s.insert(c-x);
		}
		turn = !turn;
	}
	printf("%d\n",ans );
}