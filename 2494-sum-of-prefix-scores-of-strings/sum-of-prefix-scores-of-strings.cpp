struct Node{
    Node* links[26];
    int prefixCount=0;

    bool containsKey(char c){
        return (links[c-'a']!=NULL);
    }

    void put(char c,Node* node){
        links[c-'a']=node;
    }

    Node* get(char c){
        return links[c-'a'];
    }

    void increasePrefixCount(){
        prefixCount++;
    }

};


class Solution {

private:

    Node* root = new Node();

    void insert(string &word){
        Node* node = root;
        for(char &c:word){
            if(!node->containsKey(c)){
                node->put(c,new Node());
            }
            node=node->get(c);
            node->increasePrefixCount();
        }
    }

    int getScore(string&word){
        Node* node=root;
        int score=0;
        for(char &c:word){
            node=node->get(c);
            score+=node->prefixCount;
        }
        return score;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for(string &word:words){
            insert(word);
        }
        vector<int>ans;
        for(string &word:words){
            ans.push_back(getScore(word));
        }
        return ans;
    }
};