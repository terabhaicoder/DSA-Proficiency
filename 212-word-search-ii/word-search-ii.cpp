class TrieNode {
public:
    char value;
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(char val) {
        value = val;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
        isEndOfWord = false;
    }
};

class Solution {
public:
    TrieNode* root;

    Solution() {
        root = new TrieNode('\0');
    }

    void insertWord(const string& word) {
        TrieNode* currentNode = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode(ch);
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words) {
            insertWord(word);
        }

        set<string> foundWords;
        string currentWord = "";
        int numRows = board.size();
        int numCols = board[0].size();
        vector<vector<bool>> visited(numRows, vector<bool>(numCols, false));

        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                searchWords(board, foundWords, root, row, col, currentWord, visited);
            }
        }

        return vector<string>(foundWords.begin(), foundWords.end());
    }

    void searchWords(vector<vector<char>>& board, set<string>& foundWords, TrieNode* currentNode, int row, int col, string& currentWord, vector<vector<bool>>& visited) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || visited[row][col]) return;

        char currentChar = board[row][col];
        if (currentNode->children[currentChar - 'a'] == nullptr) return;

        currentWord.push_back(currentChar);
        currentNode = currentNode->children[currentChar - 'a'];

        if (currentNode->isEndOfWord) foundWords.insert(currentWord);

        visited[row][col] = true;
        searchWords(board, foundWords, currentNode, row + 1, col, currentWord, visited);
        searchWords(board, foundWords, currentNode, row - 1, col, currentWord, visited);
        searchWords(board, foundWords, currentNode, row, col + 1, currentWord, visited);
        searchWords(board, foundWords, currentNode, row, col - 1, currentWord, visited);
        visited[row][col] = false;

        currentWord.pop_back();
    }
};