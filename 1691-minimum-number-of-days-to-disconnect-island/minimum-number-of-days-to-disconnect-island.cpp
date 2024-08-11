class Solution {
public:

    void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == 0 || visited[i][j]){
            return ;
        }
        visited[i][j] = true;

        DFS(grid, i+1, j, visited);
        DFS(grid, i-1, j, visited);
        DFS(grid, i, j+1, visited);
        DFS(grid, i, j-1, visited);
    }

    int numberOfIsland(vector<vector<int>> &grid, int m, int n){

        vector<vector<bool>> visited(m, vector<bool>(n));

        int islands = 0;
        for(int i=0; i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    DFS(grid,i,j,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = numberOfIsland(grid,m,n);  //1

        if(islands>1 || islands == 0){
            return 0;
        }
        else{
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;

                        islands = numberOfIsland(grid,m,n);
                        grid[i][j] = 1;

                        if(islands>1 or islands==0){
                            return 1;
                        }
                    }
                }
            }
        }
        return 2;
    }
};