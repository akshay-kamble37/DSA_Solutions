class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<int>>& grid){

        grid[row][col] = 1;

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        for(int i=0;i<4;i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 0){
                dfs(newrow,newcol,n,m,grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n <= 1 || m <= 1) return 0;

        //UPPER EDGE 
        for(int i=0;i<m;i++){
            if(grid[0][i] == 0){
                dfs(0,i,n,m,grid);
            }
        }
        //LOWER EDGE
        for(int i=0;i<m;i++){
            if(grid[n-1][i] == 0){
                dfs(n-1,i,n,m,grid);
            }
        }
        //LEFT EDGE
        for(int i=0;i<n;i++){
            if(grid[i][0] == 0){
                dfs(i,0,n,m,grid);
            }
        }
        //RIGHT EDGE
        for(int i=0;i<n;i++){
            if(grid[i][m-1] == 0){
                dfs(i,m-1,n,m,grid);
            }
        }

        int count =0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(i,j,n,m,grid);
                }
            }
        }

        return count;
    }
};