struct Node
{
	struct Node *nxt[2];
	int cnt ;
	Node(){
		cnt = 0;
		nxt[0] = nxt[1] = NULL;
	}
};
class Solution {
public:
	
    int findMaximumXOR(vector<int>& nums) {
    	int ret = 0;
    	Node *root = new Node(); 
        for(auto x : nums){
        	insert(root,x);
        	ret = max(ret,get(root,x));
        }
        return ret;
    }
    void insert(Node *root,int x){
    	struct Node *curr = root;
    	for(int i = 31;i>=0;i--){
    		curr->cnt++;
    		int wa = (((1<<i) & x) != 0);
    		if(!curr->nxt[wa]){
    			curr->nxt[wa] = new Node();
    		}
    		curr = curr->nxt[wa]; 
    		
    	}
    	curr->cnt++;
    }
    int get(Node *root , int x){
    	struct Node *curr = root;
    	cout<<curr->cnt<<endl;
    	int ret = 0;
    	for(int i = 31;i>=0;i--){
    		int wa = (((1<<i) & x) != 0);
    		if(curr->nxt[!wa] != NULL){
    			ret+=(1<<i); 
    			curr = curr->nxt[!wa];
    		}
    		else	curr = curr->nxt[wa];
    	}
    	return ret;
    }
};