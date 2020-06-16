class Solution {
public:
    string validIPAddress(string IP) {
    	if(IP.size() && Ipv4(IP))return "IPv4";
    	else if( IP.size() && Ipv6(IP))return "IPv6";
    	else	return "Neither";
    }
    bool Ipv4(string &IP){
    	if(IP.back() == '.')return false;
    	string curr ="";
    	std::vector<string>v;
    	for(auto c : IP){
    		if(c=='.'){
    			if(curr.size())
    				v.push_back(curr),curr="";
    		}
    		else{
    			if(c >'9' || c <'0')return false;
    			curr+=c;
    		}	
    	}
    	if(curr.size())v.push_back(curr);
    	if(v.size() != 4)return false;
    	for(auto a : v){
    		if(a.size()>3)return false;
    		if(a.size()>1 && a[0]=='0')return false;
    		int curr = 0;
    		int cnt = 1;
    		while(a.size()){
    			curr+=(a.back()-'0')*cnt;
    			cnt*=10;
    			a.pop_back();
    		}
    		if(curr>255)return false;
    	}
    	return true;
    }
    bool Ipv6(string &IP){
    	if(IP.back()==':')return false;
    	string curr ="";
    	std::vector<string>v;
    	for(auto c : IP){
    		if(c==':'){
    			v.push_back(curr),curr="";
    		}
    		else{
    			if((c < '0' || c > '9') && (c < 'a' || c > 'f') && (c < 'A' || c > 'F'))return false;
    			curr+=c;
    		}	
    	}
        v.push_back(curr);
    	if(v.size() != 8)return false;
    	for(auto a : v){
    		if(a.size()==0)return false;
    		if(a.size()>4)return false;
    	}
    	return true;
    }			
};