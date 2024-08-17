class TrieNode{
    public:
    TrieNode *children[26];
    bool isLeaf = false;

    TrieNode(){
        for(int i=0;i<26;i++) children[i] = NULL;
        isLeaf = false;
    }
};
TrieNode *root;
class WordDictionary {
public:
    WordDictionary() {
       root = new TrieNode() ;
    }
    
    void addWord(string word) {
        TrieNode *curr = root;
        for(int i=0;i<word.size();i++){
            if (word[i] < 'a' || word[i] > 'z') return;
            int index = word[i] - 'a';
            if(!curr->children[index]) curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->isLeaf = true;
    }
    bool searchHelper(TrieNode* curr, string word, int index) {
    if (index == word.size()) return curr->isLeaf;
    if (word[index] == '.') {
        for (int i = 0; i < 26; i++) {
            if (curr->children[i] && searchHelper(curr->children[i], word, index + 1)) return true;
        }
        return false;
    } else {
        int idx = word[index] - 'a';
        if (!curr->children[idx]) return false;
        return searchHelper(curr->children[idx], word, index + 1);
    }
}

    bool search(string word) {
    return searchHelper(root, word, 0);
}

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */