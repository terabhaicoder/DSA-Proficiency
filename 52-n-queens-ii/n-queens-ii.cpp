class Solution {
public:
    void solve(int row,int n,unordered_set<int>&cols, unordered_set<int>&diag, unordered_set<int>&antidiag, int &total ){
        if(row>=n){
            total++;
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

            solve(row+1,n,cols,diag,antidiag,total);

            cols.erase(col);
            antidiag.erase(antidiagfind);
            diag.erase(diagfind);
        }
    }

    int totalNQueens(int n) {
        int total=0;
        unordered_set<int>cols;
        unordered_set<int>diag;
        unordered_set<int>antidiag;
        solve(0,n,cols,diag,antidiag,total);
        return total;
    }
};
