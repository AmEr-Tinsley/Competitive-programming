class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<string> v;
        for(auto x : nums)v.push_back(to_string(x));
        sort(v.begin(),v.end(),cmp);
    	reverse(v.begin(),v.end());
    	while(v.size() > 1 && v.back() == "0" )v.pop_back();
    	reverse(v.begin(),v.end());
    	string ret = "";
    	for(auto x : v)ret+=x;
    	return ret;
    }
    static bool cmp(string a,string b){
    	return a+b > b+a;
    }
};