class Solution {
public:
    bool dfs(int i,int destination,vector<int> &visited,vector<vector<int>>& adj){
        if(i == destination){
            return true;
        }

        visited[i] = 1;
        for(auto it : adj[i]){
            if(visited[it] == 0){
                if(dfs(it, destination,visited,adj)){
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 0 || source == destination) return true; 

        vector<vector<int>> adj(n);
        
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(adj[0].size() == 0 || adj[destination].size() == 0) return false;

        vector<int> visited(n,0);

        if(dfs(source,destination,visited,adj)){
            return true;
        }
        return false;
    }
};