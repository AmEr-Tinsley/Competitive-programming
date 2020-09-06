class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
       	int n = (int)A.size();
       	std::vector<int> v(n);
       	for(int i = 0;i<n;i++)A.push_back(v),A.insert(A.begin(),v);       	
       	for(int i = 0;i<3*n;i++)
       		for(int j =0;j<n;j++)A[i].insert(A[i].begin(),0),A[i].push_back(0);
       	int ret = 0;
       	for(int i = 0;i<=A.size()-n;i++){
       		for(int j =0;j<=A[i].size()-n;j++){
       			ret = max(ret,count(A,B,i,j,n));
       		}
       	}
       	return ret;
    }
    int count(vector<vector<int>>& A,vector<vector<int>>& B,int x,int y,int n){
    	int ret = 0;
    	for(int i1=0,i2=x;i1<n && i2<x+n;i1++,i2++){
    		for(int j1=0,j2=y;j1<n && j2<y+n;j1++,j2++){
    			ret+= (int)((A[i2][j2] == B[i1][j1]) & A[i2][j2]) ;
    		}
    	}
    	return ret;
    }
};