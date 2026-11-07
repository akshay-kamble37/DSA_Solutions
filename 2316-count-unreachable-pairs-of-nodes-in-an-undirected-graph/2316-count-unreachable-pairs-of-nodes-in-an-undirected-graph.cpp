class Solution {
public:

    void dfs(int node,int &size,vector<int>& visited,vector<vector<int>>& adj)
    {
        visited[node] = 1;
        size++;

        for(auto next : adj[node]){
            if(!visited[next]){
                dfs(next,size,visited,adj);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n,0);
        vector<int> compSizes;

        for(int i=0;i<n;i++){

            if(!visited[i]){

                int size = 0;
                dfs(i,size,visited,adj);

                compSizes.push_back(size);
            }
        }

        long long ans = 0;
        long long remaining = n;

        for(auto size : compSizes){

            ans += 1LL * size * (remaining - size);
            remaining -= size;
        }

        return ans;
    }
};