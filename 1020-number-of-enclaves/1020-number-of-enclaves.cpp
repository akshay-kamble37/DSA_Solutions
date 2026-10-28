class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<int>>& grid){   // ATMOST O (n*m)

        grid[row][col] = 0;

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,-1,0,+1};

        for(int i=0;i<4;i++){                     // O(4)
            int newrow = row+delrow[i];
            int newcol = col+delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1){

                grid[newrow][newcol] = 0;
                dfs(newrow,newcol,n,m,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //UPPER EDGE                                // O(m)
        for(int i=0;i<m;i++){
            if(grid[0][i] == 1){
                dfs(0,i,n,m,grid);
            }
        }

        //LOWER EDGE                                // O(m)
        for(int i=0;i<m;i++){
            if(grid[n-1][i] == 1){
                dfs(n-1,i,n,m,grid);
            }
        }

        //LEFT EDGE                                 // O(n)        
        for(int i=0;i<n;i++){
            if(grid[i][0] == 1){
                dfs(i,0,n,m,grid);
            }
        }

        //RIGHT EDGE                                // O(n)
        for(int i=0;i<n;i++){
            if(grid[i][m-1] == 1){
                dfs(i,m-1,n,m,grid);
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){                       // O (n*m)
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    count+=1;
                }
            }
        }

        return count;
    }
};


/* APPROACH 

TRAVERSING ALL THE EDGES OF THE MATRIX AND APPLYING DFS ON EACH UNVISITED ONE

Time Complexity
O(N×M)\boxed{O(N \times M)}O(N×M)​

Reason:

Boundary traversal = O(N + M)
DFS visits each cell at most once = O(N × M)
Final counting traversal = O(N × M)

Overall:

O(N×M)O(N \times M)O(N×M)
Space Complexity
O(N×M)\boxed{O(N \times M)}O(N×M)​

Reason:

No extra visited array.
Recursive call stack can grow up to N × M in the worst case.


*/