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
		int n,k;
		scanf("%d %d",&n,&k);
 
		if(n>=k && (n-(k-1))%2){
			printf("YES\n");
			for(int i=0;i<k-1;i++)printf("1 ");
			printf("%d\n",n-k+1 );
		}
		else if(n>(k-1)*2 && (n-(k-1)*2)%2==0){
			printf("YES\n");
			for(int i=0;i<k-1;i++)printf("2 ");
			printf("%d\n",n-2*(k-1));
		}
		else	printf("NO\n");
	}
 
}