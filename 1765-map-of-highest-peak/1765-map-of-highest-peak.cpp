class Solution {
public:
    void check(vector<vector<int>>& mat,int n,int m, queue<pair<int,int>>& q,vector<vector<int>>& ans,vector<vector<int>>& visited,int &count){
        
        int dis = 0 ; 

        while( ! q.empty()){

            int size = q.size();
            dis+=1;
            if(count == 0) return;
            
            for(int i=0;i<size;i++){
                
                if(count == 0) break;

                auto it = q.front();
                int row = it.first;
                int col = it.second;
                q.pop();

                //LEFT
                if(col-1 >= 0 && mat[row][col-1] == 0 && visited[row][col-1] == 0){
                    visited[row][col-1] = 1;
                    ans[row][col-1] = dis;
                    q.push({row,col-1});
                    count--;
                }

                //RIGHT
                if(col+1 < m && mat[row][col+1] == 0 && visited[row][col+1] == 0){
                    visited[row][col+1] = 1;
                    ans[row][col+1] = dis;
                    q.push({row,col+1});
                    count--;
                }

                //UP
                if(row-1 >= 0 && mat[row-1][col] == 0 && visited[row-1][col] == 0){
                    visited[row-1][col] = 1;
                    ans[row-1][col] = dis;
                    q.push({row-1,col});
                    count--;
                }
                
                //DOWN
                if(row+1 < n && mat[row+1][col] == 0 && visited[row+1][col] == 0){
                    visited[row+1][col] = 1;
                    ans[row+1][col] = dis;
                    q.push({row+1,col});
                    count--;
                }
            }
        }
        return ;
        
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n,vector<int> (m,0));
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<int,int>> q;

        int count = n * m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    ans[i][j] = 0;
                    visited[i][j] = 1;
                    q.push({i,j});
                    count--;
                }
            }
        }
        check(mat,n,m,q,ans,visited,count);

        return ans;
    }
};

/* APPROACH --

APPLYING BFS 

*/