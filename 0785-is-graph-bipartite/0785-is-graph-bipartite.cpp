class Solution {
public:
    bool dfs(int i,int depth,vector<int>& visited,vector<int>& dis,vector<vector<int>>& graph){
        visited[i] = 1;
        dis[i] = depth + 1;
        for(auto next: graph[i]){
            if(! visited[next]){
                if( ! dfs(next,depth+1,visited,dis,graph)){
                    return false;
                }
            }
            if((dis[i] - dis[next] + 1) % 2 != 0) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n,0);
        vector<int> dis(n,0);

        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                visited[i] = 1;
                dis[i] = 0;
                if( ! dfs(i,0,visited,dis,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};

/* APPROACH - 

APPLYING DFS ON THE GRAPH - 

step 1 : Traverse the graph in the depth and for each depth maintain the distance from the starting node
step 2 : for each node mainatin distance vector and visited vector
step 3 : If cycle detected .. Cycle should be even length 
step 4 : cycle length is odd return false

*/