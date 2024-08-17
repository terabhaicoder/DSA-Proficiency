class Trie {
public:
    struct trienode{
        bool isEndOfWord;
        trienode* children[26];
    };
    trienode* getnode(){
        trienode* newnode = new trienode();
        newnode->isEndOfWord = false;
        for(int i=0;i<26;i++) newnode->children[i] = NULL;

        return newnode;
    }
    trienode *root;
    Trie() {
        root = getnode();
    }
    
    void insert(string word) {
        trienode *crawler = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getnode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }
    
    bool search(string word) {
        trienode *crawler = root;
        for(auto ch: word){
            int idx = ch - 'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler = crawler->children[idx];
        }
        if(crawler!=NULL && crawler->isEndOfWord==true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trienode *crawler = root;
        for(auto ch: prefix){
            int idx = ch - 'a';
            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler = crawler->children[idx];
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