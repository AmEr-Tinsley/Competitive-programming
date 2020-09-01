class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        pair<int,int>best ={-1,-1};
        do{
        	int h = A[1]+A[0]*10;
   			int m = A[3]+A[2]*10;
   			if(h<24 && m<60){
   				best = max(best,{h,m});
   			}
        }while(next_permutation(A.begin(),A.end()));
        if(best.first == -1)return "";
        string h = to_string(best.first);
        string m = to_string(best.second);
        if(h.size() == 1)h = "0"+h;
        if(m.size() == 1)m = "0"+m
        return h + ":" + m;
    }
};