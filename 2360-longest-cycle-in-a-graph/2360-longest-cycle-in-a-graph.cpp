class Solution {
public:
    int dfs(int node,int value,vector<int>& edges,vector<int>& visited,vector<int>& dis,vector<int>& cycle){
        visited[node] = 1;
        cycle[node] = 1;
        dis[node] = value;

        int next = edges[node];

        if(next == -1){
            cycle[node] = 0;
            return -1;
        }

        if(visited[next] == 0){
            int ans =  dfs(next,value+1,edges,visited,dis,cycle);
            cycle[node] = 0;
            return ans;
        }
        
        if(cycle[next] == 1){
            cycle[node] = 0;
            return value - dis[next] + 1;
        }
        cycle[node] = 0;
        return -1;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> dis(n,0);
        vector<int> visited(n,0); 
        vector<int> cycle(n,0);

        int maxi = -1;

        for(int i=0;i<n;i++){
            if( visited[i] == 0 ){
                visited[i] = 1;
                dis[i] = 0;
                cycle[i] = 1;
                int value  = dfs(i,0,edges,visited,dis,cycle);
                maxi = max(maxi,value);
            }
        }
        return maxi;
    }
};