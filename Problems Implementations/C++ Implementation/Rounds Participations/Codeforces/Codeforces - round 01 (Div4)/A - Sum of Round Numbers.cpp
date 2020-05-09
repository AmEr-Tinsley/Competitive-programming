#include<bits/stdc++.h>
 
using namespace std;
 
bool check(int x){
	while(x>=10){
		if(x%10)return false;
		x/=10;
	}
	return true;
}
int main(){
 
	int tc;
 
	scanf("%d",&tc);
 
	while(tc--){
		int n;
		scanf("%d",&n);
		std::vector<int> ans;
		for(int i=10000;i>=1;i--){
			if(i<=n && check(i)){
				n-=i;
				ans.push_back(i);
			}
		}
		printf("%d\n",ans.size() );
		for(auto x : ans)printf("%d ",x );
		printf("\n");
	}
 
}