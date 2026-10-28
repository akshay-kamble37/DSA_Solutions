class Solution {
public:

    void dfs(int row,int col,int n,int m,vector<vector<char>>& board){

        board[row][col] = '#';

        int delrow[] = {-1,0,+1,0};
        int delcol[] = {0,-1,0,+1};

        for(int i=0;i<4;i++){
            int newrow = row+delrow[i];
            int newcol = col+delcol[i];

            if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && board[newrow][newcol] == 'O'){

                board[newrow][newcol] = '#';
                dfs(newrow,newcol,n,m,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        //UPPER EDGE    
        for(int i=0;i<m;i++){
            if(board[0][i] == 'O'){
                dfs(0,i,n,m,board);
            }
        }

        //LOWER EDGE
        for(int i=0;i<m;i++){
            if(board[n-1][i] == 'O'){
                dfs(n-1,i,n,m,board);
            }
        }

        //LEFT ROW
        for(int i=0;i<n;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,n,m,board);
            }
        }

        //RIGHT ROW
        for(int i=0;i<n;i++){
            if(board[i][m-1] == 'O'){
                dfs(i,m-1,n,m,board);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
        
        return ;
    }
};

/* APPROACH 

OPTIMIZING THE APPROACH BY REMOVING VISITED ARRAY AND ALTERING THE BOARD ITSELF.


APPLYING DFS IN THE EDGE 'O' 

TRAVERSING ALL THE EDGE OF THE MATRIX BY 'O'

step 1: Checking the possible 'O' which is visited by the edge 'O'
step 2: For all the DFS call marking the cell as the visited cell
step 3: After all the DFS call, convert the unmarkder cell to "X";

Time Complexity:
O*N × M)

Reason*
Boundary traversal takes O(N + M)*
*FS visits each cell at most once, *aking*O(N × M).
Final traversal of*the matrix also takes O(N × M).

H*nce overall complexity is O(N × M)*

Space Complexity:
O(N × M)

Reas*n:
An additional visited matrix of*size N × M is used.
The recursive *FS stack can*also grow up to O(N ×*M) in the worst case.
Therefore*the total auxiliary*space is O(N × M).

*/