class Solution {
public:
    void solve(int row,int n, vector<string>&board,unordered_set<int>&cols, unordered_set<int>&diag, unordered_set<int>&antidiag, vector<vector<string>>&result ){
        if(row>=n){
            result.push_back(board);
            return;
        } 
        for(int col=0;col<n;col++){
            int diagfind = row + col;
            int antidiagfind = row - col;
            if(cols.find(col)!=cols.end() || diag.find(diagfind)!=diag.end() || 
            antidiag.find(antidiagfind)!=antidiag.end()){
                continue;
            }
            cols.insert(col);
            antidiag.insert(antidiagfind);
            diag.insert(diagfind);
            board[row][col] = 'Q';

            solve(row+1,n,board,cols,diag,antidiag,result);

            cols.erase(col);
            antidiag.erase(antidiagfind);
            diag.erase(diagfind);
            board[row][col] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        vector<vector<string>>result;
        unordered_set<int>cols;
        unordered_set<int>diag;
        unordered_set<int>antidiag;
        solve(0,n,board,cols,diag,antidiag,result);
        return result;
    }
};