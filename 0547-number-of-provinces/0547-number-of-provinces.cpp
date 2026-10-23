class Solution {
public:

    void dfs(int i,vector<int> &visited,vector<vector<int>> &adj){
        visited[i] = 1;
        for(auto it:adj[i]){
            if(!visited[it]){
                dfs(it,visited,adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected[0].size();
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && isConnected[i][j] == 1)
                    adj[i+1].push_back(j+1);
            }
        }
        vector<int> visited(n+1,0);
        int count=0;
        for(int i=1;i<n+1;i++){
            if(visited[i] == 0){
                visited[i]=1;
                count++;
                dfs(i,visited,adj);
            }
        }
        return count;
    }
};


/* APPROACH 

SOLVE USING DEPTH FIRST SEARCH

step 1 : Picking each node and traversing all the node in depth or marking all the node
         in visited array 
step 2 : As we pick new element for the dfs increases the count .
step 3 : Repeating step 1 until all nodes are not complete
step 4 : Returning the Count 

*/