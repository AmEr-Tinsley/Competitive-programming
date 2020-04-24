#include<bits/stdc++.h>
using namespace std;
class ValueDivision
{	public: 
	vector<int> getArray(vector<int> a){
			int n = (int)a.size();
        	map<int,vector<int> > occ;
        	for(int i = 0 ; i <n ; i++)occ[a[i]].push_back(i);
        	std::map<int,vector<int>>::reverse_iterator it;
       		for(it=occ.rbegin(); it!=occ.rend(); ++it){
            		if (it->first == 1)continue;
            		vector <int> &v = it->second;
            		sort(v.begin(),v.end());
            		for(int i=0;i<(int)v.size()-1;i++){
	                	a[v[i]]--;
	                	occ[a[v[i]]].push_back(v[i]);
            		}
       	    }
        	return a;
	}
};