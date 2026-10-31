class Solution {
public:
    bool dfs(int row,int col,int lastrow,int lastcol,int n,int m,char c,vector<vector<char>>& grid,vector<vector<int>> &visited){
        
        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,+1,0,-1};

        for(int i=0;i<4;i++){                               //O(4)
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && visited[newrow][newcol] == 1 && grid[newrow][newcol] == c){
                if(newrow != lastrow || newcol != lastcol)
                    return true;
            }

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && visited[newrow][newcol] == 0 && grid[newrow][newcol] == c){
                visited[newrow][newcol] = 1;
                if(dfs(newrow,newcol,row,col,n,m,c,grid,visited))
                    return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n <= 1 || m <= 1) return false;

        vector<vector<int>> visited(n,vector<int> (m,0));

        for(int i=0;i<n;i++){                                       // O(n*m)
            for(int j=0;j<m;j++){
                if(visited[i][j] == 0){
                    char c = grid[i][j];
                    visited[i][j] = 1;
                    if(dfs(i,j,-1,-1,n,m,c,grid,visited)){         // Atmost O(n*m)
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


/* APPROACH 

APPLYING THE DFS ALGORITHM HERE- 

step 1 : Creating the visited array means we have the record of the visited cell for each time - which helps to detect the cycle 
step 2 : If the cell is not visited applying DFS on that cell and marking it as visited '1'
step 3 : For each cell checking the 3 direction and left that direction from where the DFS is called
step 4 : if Cycle is detected at new cell return true else check for the another cell 

*/

//Time complexity  = O(n*m) 

//Space complexity = visited array O(n*m) + recursive stack 