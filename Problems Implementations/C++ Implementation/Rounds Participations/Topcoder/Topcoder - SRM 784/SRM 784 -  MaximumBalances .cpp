#include<bits/stdc++.h>
using namespace std;
class MaximumBalances
{
	public: 
	int solve(string s){
		int op = 0;
		int cl = 0;
		for(auto c : s)op+=(c=='('),cl+=(c==')');
		return min(cl,op)*(min(cl,op)+1)/2;
	}
	
};