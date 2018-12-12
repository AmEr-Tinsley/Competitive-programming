#include <bits/stdc++.h>
 
using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long
 
const int N=200,MOD=1e9+7;
 
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m,sx,sy;
string a[N];
std::vector<pair<int,int>> ex;
int dist[N][N][16];
bool vis[N][N][16];
 
int key(char c){
    if(c == 'b')
         return 0;
    if(c == 'y')
         return 1;
    if(c == 'r')
         return 2;
    if(c == 'g')
         return 3;
    return -1;
}
void take(int x,int y,int &state){
 
     if(key(a[x][y])!=-1){
         state|=(1<<key(a[x][y]));
     }
}
bool ok(int x,int y,int state){
 
     if(x>=n || y>=m || x<0 || y<0 || vis[x][y][state] || a[x][y] == '#')return false;
 
     if(a[x][y]=='B')return (1<<0 & state);
     if(a[x][y]=='Y')return (1<<1 & state);
     if(a[x][y]=='R')return (1<<2 & state);
     if(a[x][y]=='G')return (1<<3 & state);
     return true;
}
void bfs(){
     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<16;k++)
                dist[i][j][k]=1e9;
     queue<pair<pair<int,int>,int>>q;
     q.push({{sx,sy},0});
     memset(vis,0,sizeof(vis));
     dist[sx][sy][0]=0;
 
     while(!q.empty()){
 
          int x = q.front().first.first , y = q.front().first.second , state = q.front().second;
          q.pop();
          vis[x][y][state]=1;
          int cost = dist[x][y][state];
          take(x,y,state);
          
          for(int i=0;i<4;i++){
               if(ok(dx[i]+x,dy[i]+y,state) && dist[dx[i]+x][dy[i]+y][state] > cost + 1){
                     dist[dx[i]+x][dy[i]+y][state]=cost + 1;
                     q.push({{dx[i]+x,dy[i]+y},state});
               }
          }
     }
 
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif
          
            while(cin>>n>>m,n!=0){
 
                 ex.clear();
 
                 for(int i=0;i<n;i++)
                    cin>>a[i];
                 for(int i=0;i<n;i++){
                     for(int j=0;j<m;j++){
                          if(a[i][j]=='*')
                            sx=i,sy=j;
                          else if(a[i][j]=='X')
                            ex.pb({i,j});
                     }
                 }
                 bfs();
                 int ans=1e9;
                 for(auto p:ex){
                      for(int i=0;i<16;i++)
                      ans = min(ans,dist[p.first][p.second][i]);
                 }
 
                 if(ans==1e9)
                    cout<<"The poor student is trapped!\n";
                 else
                    cout<<"Escape possible in "<<ans<<" steps.\n";
            }
    
    return 0;
 
}  