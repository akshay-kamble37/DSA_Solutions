class Solution {
public:
    void check(vector<vector<int>>& image, int n, int m,int row,int col,queue<pair<int,int>>& q,int color,int flood_color){

        //LEFT
        if(col-1 >= 0 && image[row][col-1] == flood_color){
            image[row][col-1] = color;
            q.push({row,col-1});
        }

        //RIGHT
        if(col+1 < m && image[row][col+1] == flood_color){
            image[row][col+1] = color;
            q.push({row,col+1}); 
        }

        //UP
        if(row-1 >= 0 && image[row-1][col] == flood_color){
            image[row-1][col] = color;
            q.push({row-1,col});
        }
        
        //DOWN
        if(row+1 < n && image[row+1][col] == flood_color){
            image[row+1][col] = color;
            q.push({row+1,col});
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        if(image[sr][sc] == color) return image;

        queue<pair<int,int>> q; // FOR BFS TRAVERSAL

        int flood_color = image[sr][sc] ;
        image[sr][sc] = color;
        q.push({sr,sc});

        while(! q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto data = q.front();
                int row = data.first;
                int col = data.second;
                q.pop();

                check(image,n,m,row,col,q,color,flood_color);
            }
        }

        return image;
        
    }
};

/* APPROACH

APPLYING BFS - WE CAN ALSO SOLVE IT BY DFS

base condition : If given cell color is already matches the coloring color return image without modifying

step 1 : Given starting cell, check all the Adjacent cell.
step 2 : if cell color matches add it to the queue.
step 3 : read each pair in the queue modify the color.
step 4 : Repeat process until Queue is not empty.

*/