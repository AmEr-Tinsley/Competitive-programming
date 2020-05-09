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
		int a,b,c;
 
		scanf("%d %d %d",&a,&b,&c);
 
		if(c)for(int i=0;i<=c;i++)printf("1");
		if(a)for(int i=0;i<=a;i++)printf("0");
		if(!a){
			int turn = 0;
			if(!c){	
				
				if(b)for(int i=0;i<=b;i++)printf("%d",turn ),turn = !turn;
			}
			else{
				for(int i = 0;i<b;i++)printf("%d",turn ),turn = !turn;
			}
		}
		else{
			int turn = 1;
			if(!c){
				for(int i=0;i<b;i++)printf("%d",turn ),turn =!turn;
			}
			else{
				for(int i=1;i<b;i++)printf("%d",turn ),turn = !turn;
			}
		}
		printf("\n");
	}
 
}