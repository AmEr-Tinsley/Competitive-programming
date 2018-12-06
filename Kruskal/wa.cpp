#include <bits/stdc++.h>

using namespace std;
int n;
std::vector<pair<double,pair<int,int> > > arete;
pair<int,int> point[55];
std::vector<pair<int,double>> cablage[55];
int rep[55];
int find(int u){
	 if(rep[u]==u)return u;
	 return rep[u]=find(rep[u]);
}
double total;
void affichage(int u,int p){

      for(int i=0;i<(int)cablage[u].size();i++){
          pair<int,double> v = cablage[u][i];
      	  if(v.first!=p){
               printf("Câble nécessaire pour connecter (%d,%d) à (%d,%d) : %.2lf mètres.\n",point[u].first,point[u].second,point[v.first].first,point[v.first].second,v.second);
               total+=v.second;
               affichage(v.first,u);
      	  }
      }
}
int main(){

	 freopen("connexion.in","r",stdin);
	 freopen("connexion.out","w",stdout);
      int cnt = 1;
	  while(scanf("%d",&n),n!=0){
	  	if(cnt !=1)
	  	printf("\n");
	  	 printf("**********************************************************\nRESEAU #%d\n",cnt);
	  	  total = 0;
	  	  arete.clear();
	  	  for(int i=0;i<55;i++)cablage[i].clear();
          for(int i=0;i<n;i++)scanf("%d %d",&point[i].first,&point[i].second);
          for(int i=0 ;i<n;i++){
          	 for(int j=i+1;j<n;j++){
              double distance = sqrt((point[i].first-point[j].first)*(point[i].first-point[j].first) + (point[i].second-point[j].second)*(point[i].second-point[j].second))+16;
              arete.push_back({distance,{i,j}});
          	 }
          }
          for(int i=0;i<n;i++)rep[i]=i;
           sort(arete.begin(),arete.end());

         for(int i=0;i<(int)arete.size();i++){

               int u = arete[i].second.first , v = arete[i].second.second  ;

               double distance = arete[i].first;

               int p1 = find(u) , p2 = find(v) ;

               if(p1==p2 || (int)cablage[u].size()==2 || (int)cablage[v].size()==2 ) continue;

               cablage[u].push_back({v,distance});
               cablage[v].push_back({u,distance});
               rep[p1]=rep[p2];
         }
         int start;
         for(int i=0;i<n;i++){
         	  if((int)cablage[i].size()==1){
         	  	 	  start=i;
         	  	 	  break;
         	  }
         }


         affichage(start,-1);

         printf("Longueur totale de câble nécessaire : %.2lf.",total );

         cnt++;

	  }
}
