class Solution {
public:
    int compareVersion(string version1, string version2) {
     	vector<string> a = split(version1);
     	vector<string> b = split(version2);

     	while(a.size() && a.back() == "0")a.pop_back();
     	while(b.size() && b.back() == "0")b.pop_back();
     	for(auto x : a)cout<<x<< " ";
     	cout<<endl;
     	for(auto x : b)cout<<x<<" ";
     	cout<<endl;
     	for(int i =0;i<min(a.size(),b.size());i++){
     		if(a[i] != b[i]){
     			if(a[i].size()!=b[i].size())return (a[i].size()>b[i].size())? 1 : -1;
     			return (a[i]>b[i]) ? 1 : -1;
     		}
     	}
     	return (a.size()>b.size()) ? 1 : ((b.size()>a.size())? -1 : 0); 
    }

    vector<string>split(string & a){
    	string curr = "";
    	std::vector<string> ret;
    	for(auto x : a){
    		if(x=='.'){
    			reverse(curr.begin(),curr.end());
    			while(curr.size() && curr.back()=='0')curr.pop_back();
    			if(curr.size()==0)curr="0";
    			reverse(curr.begin(),curr.end());
    			ret.push_back(curr);
                curr = "";
    		}
            else   curr+=x;
    	}
        reverse(curr.begin(),curr.end());
    	while(curr.size() && curr.back()=='0')curr.pop_back();
    	if(curr.size()==0)curr="0";
    	reverse(curr.begin(),curr.end());
    	ret.push_back(curr);
    	return ret;
    }
};