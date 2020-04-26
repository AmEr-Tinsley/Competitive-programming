class Scissors
{	
	public :
	int openingTime(int n){
		int curr = 1;
		int ans = 0;
		while(curr<=n){
			curr*=2;
			ans+=10;
		}
		return ans;
	}
	
};