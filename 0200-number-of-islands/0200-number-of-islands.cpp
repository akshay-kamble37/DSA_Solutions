class Solution {
public:
    void dfs(int row,int col,int &vertical,int &hori,vector<vector<char>>& grid,vector<vector<int>>& visited){
        visited[row][col] = 1;

        //RIGHT
        if(col+1 < hori && grid[row][col+1] == '1' && visited[row][col+1] == 0){
            dfs(row,col+1,vertical,hori,grid,visited);
        }

        //DOWN
        if(row+1 < vertical && grid[row+1][col] == '1' && visited[row+1][col] == 0){
            dfs(row+1,col,vertical,hori,grid,visited);
        }

        //LEFT
        if(col-1 >= 0  && grid[row][col-1] == '1' && visited[row][col-1] == 0){
            dfs(row,col-1,vertical,hori,grid,visited);
        }

        //UP
        if(row-1 >= 0 && grid[row-1][col] == '1' && visited[row-1][col] == 0){
            dfs(row-1,col,vertical,hori,grid,visited);
        }

    }


    int numIslands(vector<vector<char>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        
        vector<vector<int>> visited(n,vector<int> (m,0));

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    dfs(i,j,n,m,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};