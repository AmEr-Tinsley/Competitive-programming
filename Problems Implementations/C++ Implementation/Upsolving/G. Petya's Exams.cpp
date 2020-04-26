  //                                                   ¯\_(ツ)_/¯
  //#pragma GCC optimize("Ofast")
 //#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
#define pi pair<int,int>
const int N=5005,MOD=998244353;

using namespace std;

int n,m;
int ans[105],id[105];
bool pop[105];
int main() {

#ifndef ONLINE_JUDGE
	freopen("tst.txt", "r", stdin);
#endif

		scanf("%d %d",&n,&m);

		priority_queue<pair<pi,int>,vector<pair<pi,int>> ,greater<pair<pi,int>>>q;
		for(int i=1,s,d,c;i<=m;i++){

				scanf("%d %d %d",&s,&d,&c);
				ans[d]=m+1;
				id[d]=i;
				q.push({{d,c},s});
		}

		for(int i=1;i<=n;i++){

				if(ans[i]){
					 if(!pop[id[i]])return !printf("-1\n");
				}
				else{
					queue<pair<pi,int>>aux;

					while(sz(q) && q.top().second>i)aux.push(q.top()),q.pop();

					if(sz(q)){
						 pair<pi,int> p = q.top();
						 q.pop();
						 p.first.second = p.first.second - 1;
						 ans[i]=id[p.first.first];
						 if(p.first.second)q.push(p);
						 else pop[id[p.first.first]]=true;
					}
					else{
						 ans[i]=0;
					}

					while(!aux.empty())q.push(aux.front()),aux.pop();
				}
		}


		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");

}
