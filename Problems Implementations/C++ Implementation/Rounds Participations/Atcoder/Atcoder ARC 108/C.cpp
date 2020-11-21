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

int n,m,root[N];
int find(int u){
	if(root[u]==u)return u;
	return root[u] = find(root[u]);
}
int occ[N];
bool cmp(const pair<pair<int,int>,int>&a,const pair<pair<int,int>,int>&b){
	return (min(occ[a.first.first],occ[a.first.second]) <= min(occ[b.first.first],occ[b.first.second]));
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file();
	scanf("%d %d",&n,&m);
	vector<pair<pair<int,int>,int>> edges;
	for(int i =1;i<=n;i++)root[i]=i;
	for(int i=0;i<m;i++){
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		edges.pb({{x,y},c});
		occ[x]++;
		occ[y]++;
	}
	sort(all(edges),cmp);
	vector<vector<int>>should_not_be(n+1);
	std::vector<int>assignedValue(n+1);
	for(auto p : edges){
		int x = p.first.first , y = p.first.second , c = p.second;
		int p1 = find(x),p2 = find(y);
		if(p1 != p2){
			if(occ[x]>occ[y])swap(x,y);
			if(!assignedValue[x]){
				if(assignedValue[y] == c){
					should_not_be[x].pb(c);
					root[x] = root[y];
				}
				else{
					assignedValue[x] = c;
					should_not_be[y].pb(c);
					root[x] = root[y];
				}	
			}
			else if(!assignedValue[y]){
				if(assignedValue[x] == c){
					should_not_be[y].pb(c);
					root[x] = root[y];
				}
				else{
					assignedValue[y] = c;
					should_not_be[x].pb(c);
					root[x] = root[y];
				}	
			}
		}
	}

	for(int i = 1;i<=n;i++){
		if(!assignedValue[i]){
			int v = 1;
			sort(all(should_not_be[i]));
			for(auto x : should_not_be[i]){
				if(x == v)v++;
				else{
					assignedValue[i] = v;
					break;
				}
			}
		}
		if(!assignedValue[i])return !printf("No\n");
	}

	for(int i = 1;i<=n;i++)printf("%d\n",assignedValue[i]);
}