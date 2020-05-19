class StockSpanner {
public:
	std::vector<int> seg;
	int cnt,N;
    StockSpanner() {
    	N = 100005;
        seg = std::vector<int>(4*N,-1);
        cnt = 0;
    }

    void update(int indx,int l,int r,int pos){
    	if(l==r){
    		seg[indx] = cnt;
    		return;
    	}
    	if(pos<=(l+r)/2)update(2*indx,l,(l+r)/2,pos);
    	else	update(2*indx+1,(l+r)/2+1,r,pos);
    	seg[indx] = max(seg[indx*2],seg[indx*2+1]);
    }
    int get(int indx,int l,int r,int i,int j){
    	if(l>j || r<i)return -1;
    	if(l>=i && r<=j)return seg[indx];
    	return max(get(indx*2,l,(l+r)/2,i,j),get(indx*2+1,(l+r)/2+1,r,i,j));
    }
    
    int next(int price) {
        int wa = get(1,0,N-1,price+1,N-1);
        update(1,0,N-1,price);
        return (cnt++)-wa;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */