#include <bits/stdc++.h>
using namespace std;

class EllysWhatDidYouGet
{
public:
		int getCount(int n){
			int ret = 0;
			for(int i=1;i<=50;i++){
				for(int j=1;j<=50;j++){
					for(int k=1;k<=50;k++){
						int X = (i + j) * k;
						int needed = 0;
						while(X)needed+=X%10,X/=10;
						bool ok = true;
						for(int z=2;z<=n;z++){
							int X = (i*z + j) * k;
							int curr = 0;
							while(X)curr+=X%10,X/=10;
							if(curr!=needed)ok=false;
						}
						ret+=(ok==true);
					}
				}
			}
			return ret;
		}	
	
};