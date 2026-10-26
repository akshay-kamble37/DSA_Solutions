class Solution {
public:
    void dfs(int row,int col,int &size,int &vertical,int &hori,vector<vector<int>>& grid,vector<vector<int>>& visited){
        visited[row][col] = 1;

        //RIGHT
        if(col+1 < hori && grid[row][col+1] == 1 && visited[row][col+1] == 0){
            size++;
            dfs(row,col+1,size,vertical,hori,grid,visited);
        }

        //DOWN
        if(row+1 < vertical && grid[row+1][col] == 1 && visited[row+1][col] == 0){
            size++;
            dfs(row+1,col,size,vertical,hori,grid,visited);
        }

        //LEFT
        if(col-1 >= 0  && grid[row][col-1] == 1 && visited[row][col-1] == 0){
            size++;
            dfs(row,col-1,size,vertical,hori,grid,visited);
        }

        //UP
        if(row-1 >= 0 && grid[row-1][col] == 1 && visited[row-1][col] == 0){
            size++;
            dfs(row-1,col,size,vertical,hori,grid,visited);
        }

    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        
        vector<vector<int>> visited(n,vector<int> (m,0));

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    int size = 1;
                    dfs(i,j,size,n,m,grid,visited);
                    if(count < size)
                        count = size;
                }
            }
        }
        return count;
    }
};


/* APPROACH - 

APPLYING DFS 

step 1: Traversing each cell and mainating the visited array.
step 2: For each cell which is one checking the 4 Dimensionally grid.
step 3: Mainting the count for the each DFS traversal.
step 4: Returning the maximum count.

*/