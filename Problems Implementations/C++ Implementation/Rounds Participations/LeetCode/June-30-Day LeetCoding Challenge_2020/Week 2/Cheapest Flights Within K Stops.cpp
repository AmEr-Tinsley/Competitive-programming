class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
         
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
         vector<vector<pair<int,int>>>g(n);
         for(auto p : flights){
         	int u = p[0],v=p[1],w=p[2];
         	g[u].push_back({v,w});
         }
         q.push({0,{src,-1}});

         while(!q.empty()){
         	int u = q.top().second.first;
         	int cst = q.top().first;
         	int done = q.top().second.second;
         	if(u==dst)return cst;
         	q.pop();
         	if(done == K)continue;
         	for(auto p : g[u]){
         		int w = p.second,v=p.first;
         		q.push({cst+w,{v,done+1}});
         	}
         }

         return -1;
         
    }
};