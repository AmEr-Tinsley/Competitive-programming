class Trie {
public:
    /** Initialize your data structure here. */
    struct node{	
        	vector<int> edgewith;
        	bool End;
        	node(){
        		edgewith = vector<int>(26,-1);
        		End = 0; 
        	}
    };
    std::vector<node> Tree;
    Trie() {
       	Tree = vector<node>(1);
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int i = 0;
        for(auto c : word){
        	int curr = c - 'a';
        	if(Tree[i].edgewith[curr]==-1){
        		Tree[i].edgewith[curr] = Tree.size();
        		Tree.push_back(node());
        	}
        	i = Tree[i].edgewith[curr];
        }
        Tree[i].End = 1;
    }	
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int i = 0;
        for(auto c : word){
        	int curr = c - 'a';
        	if(Tree[i].edgewith[curr] == -1)return false;
        	i = Tree[i].edgewith[curr];
        }
        return Tree[i].End;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int i = 0;
        for(auto c : prefix){
        	int curr = c -'a';
        	if(Tree[i].edgewith[curr] == -1)return false;
        	i = Tree[i].edgewith[curr];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */