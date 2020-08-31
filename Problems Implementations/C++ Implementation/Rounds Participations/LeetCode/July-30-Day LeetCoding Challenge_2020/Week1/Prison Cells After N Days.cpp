class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
     	std::vector<int> Day1(8);
     	for(int i=1;i<7;i++)Day1[i] = (cells[i-1]==cells[i+1]);
     	for(int i = 0;i<8;i++)cells[i] = Day1[i];
     	N--;
     	int cycle = 1;
     	while(N--){
     		std::vector<int> wa(8);
     		for(int i=1;i<7;i++)wa[i]=(cells[i-1]==cells[i+1]);
     		if(wa == Day1)N%=cycle;
     		for(int i=0;i<8;i++)cells[i]=wa[i];
     		cycle++;
     	}
     	return cells;
    }
};