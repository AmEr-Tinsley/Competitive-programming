#include <bits/stdc++.h>
using namespace std;

class EllysDifferentPrimes
{
public:
		bool check(int x){
			if(x==1)return false;
			set<int>s;
			int X = x;
			while(X){
				if(s.count(X%10))return false;
				s.insert(X%10);
				X/=10;
			}
			for(int i = 2;i*i<=x;i++){
				if(x%i==0)return false;
			}
			return true;
		}
		int getClosest(int n){
			
			int closestleft = -1e6;
			int closestright = 1e9;
			for(int i=n;;i++){
				if(check(i)){
					closestright=i;
					break;
				}
			} 
			for(int i=n;i>=2;i--){
				if(check(i)){
					closestleft = i;
					break;
				}
			}
			if(closestright-n < n-closestleft){
				return closestright;
			}
			else return closestleft;
		}	
	
};