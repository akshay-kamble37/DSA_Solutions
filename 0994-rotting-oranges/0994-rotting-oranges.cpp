class Solution {
public:
    void calculate(vector<vector<int>>& grid,int n,int m, queue<pair<int,int>>& p,int& fresh_orange){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    p.push({i,j});
                }
                if(grid[i][j] == 1){
                    fresh_orange++;
                }
            }
        }
    }

    void check(vector<vector<int>>& grid,int row,int col,int n,int m, queue<pair<int,int>>& p,int& fresh_orange){

        //LEFT
        if(col-1 >= 0 && grid[row][col-1] == 1){
            fresh_orange--;
            p.push({row,col-1});
            grid[row][col-1] = 2;
        }

        //RIGHT
        if(col+1 < m && grid[row][col+1] == 1){
            fresh_orange--;
            p.push({row,col+1});
            grid[row][col+1] = 2;
        }        

        //DOWN
        if(row+1 < n && grid[row+1][col] == 1){
            fresh_orange--;
            p.push({row+1,col});
            grid[row+1][col] = 2;
        }

        //UP
        if(row-1 >= 0 && grid[row-1][col] == 1){
            fresh_orange--;
            p.push({row-1,col});
            grid[row-1][col] = 2;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_orange = 0;
        queue<pair<int,int>> p;

        int n = grid.size();  // ROW
        int m = grid[0].size(); //COLUMN

        calculate(grid,n,m,p,fresh_orange);

        if(fresh_orange == 0) return 0;
        int time = 0;

        while( ! p.empty()){
            int size = p.size();
            
            if(size > 0){
                time += 1;
            }

            for(int i=0;i<size;i++){
                auto value = p.front();
                int row = value.first;
                int col = value.second;
                p.pop();

                check(grid,row,col,n,m,p,fresh_orange);
            }

            if(fresh_orange == 0) return time;
        }

        if(fresh_orange != 0) return -1;
        return time;
    }
};



/* APPPROACH 

Applying the BFS algorithm 

step 1: picking the starting node (BFS) as the grid cell with the value 2.
step 2: traversing all the 4 dimensional direction of the current grid cell.
step 3: For Each level of the BFS increse time count and for each cell grid with 1 decrease the number of fresh_count.

*/