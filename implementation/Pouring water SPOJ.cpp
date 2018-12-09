#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long

const int N=1e6+5,MOD=1e9+7;

int tc,a,b,c;
map<pair<int,int>,int>wa;
map<pair<int,int>,bool>vis;
void fckoff(int a,int b,int c,int d){
     if(!wa.count({a,b}))
         wa[{a,b}]=wa[{c,d}]+1;
     else
         wa[{a,b}]=min(wa[{a,b}],wa[{c,d}]+1);
}
void bfs(){

     wa.clear();
     vis.clear();
     int cnt=0;
     queue<pair<int,int>>q;
     q.push({0,0});

     while(!q.empty()){
         cnt++;
         if(cnt==N)return;

         int a1=q.front().first , b1=q.front().second;
         vis[{a1,b1}]=true;
         q.pop();
         if( a1<a && !vis.count({a,b1}))q.push({a,b1}),fckoff(a,b1,a1,b1);
         if( b1<b && !vis.count({a1,b}))q.push({a1,b}),fckoff(a1,b,a1,b1);
         if( a1 && !vis.count({0,b1}))q.push({0,b1}),fckoff(0,b1,a1,b1);
         if( b1 && !vis.count({a1,0}))q.push({a1,0}),fckoff(a1,0,a1,b1);
         if( a1 && b1<b ){
              int pour = min(b-b1,a1);
              if(!vis.count({a1-pour,b1+pour}))
               q.push({a1-pour,b1+pour}),fckoff(a1-pour,b1+pour,a1,b1);
         }
         if( b1 && a1<a ){
              int pour = min(a-a1,b1);
              if(!vis.count({a1+pour,b1-pour}))
              q.push({a1+pour,b1-pour}),fckoff(a1+pour,b1-pour,a1,b1);
         }
     }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("test.txt","r",stdin);
#endif

      scanf("%d",&tc);

      while(tc--){
       
           scanf("%d %d %d",&a,&b,&c);

           bfs();
           int ans = 1e9;
           for(int i=0;i<=a;i++){
                if(wa.count({i,c}))
                    ans = min(ans,wa[{i,c}]);
             }
            for(int i=0;i<=b;i++){
                if(wa.count({c,i}))
                    ans = min(ans,wa[{c,i}]);
             }

             if(ans == 1e9)
                printf("-1\n");
             else
                printf("%d\n",ans );
           }
      

    
    return 0;

}