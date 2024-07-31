class Solution {
public:
    int n;
    int width;
    int t[1001][1001];
    int solve(vector<vector<int>> books, int i, int remainW, int maxH ){
        if(i >= n){
            return maxH;
        }
        if(t[i][remainW]!=-1) return t[i][remainW];
        int bookW = books[i][0];
        int bookH = books[i][1];

        int keep = INT_MAX;
        int skip = INT_MAX;

        if(bookW <= remainW){
            keep = solve(books,i+1,remainW-bookW,max(maxH,bookH));
        }

        skip = maxH + solve(books,i+1,width-bookW,bookH);

        return t[i][remainW] = min(keep,skip);
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        n = books.size();
        memset(t,-1,sizeof(t));
        width = shelfWidth;

        int remainW = shelfWidth;
        return solve(books,0,remainW,0);
    }
};