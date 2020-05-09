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
		std::vector<int> a(n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
 
		int l = 0,r=n-1 , A = 0 , B =0 , turns = 0 , aa = 0 , bb = 0;
 
		while(l<=r){
			if(turns%2){
				while(bb<=aa){
					bb+=a[r--];
					if(r<l)break;
				}
				B+=bb;
				aa = 0;
				turns++;
			}
			else{
				while(aa<=bb){
					aa+=a[l++];
					if(l>r)break;
				}
				A+=aa;
				bb = 0;
				turns++;
			}
		}
		printf("%d %d %d\n",turns,A,B);
	}
 
}