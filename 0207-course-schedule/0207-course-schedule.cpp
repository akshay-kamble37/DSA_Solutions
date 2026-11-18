class Solution {
public:
    bool dfs(int i,int n,vector<int> &visited,vector<int>& cycle,vector<vector<int>>& adj){
        if(cycle[i] == 1){
            return true;
        }
        cycle[i] = 1;
        visited[i] = 1;
        for(auto it : adj[i]){
            if(!visited[it]){
                if(dfs(it,n,visited,cycle,adj)){
                    return true;
                }
            }
            else if(cycle[it]){
                return true;
            }
        }
        cycle[i] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int> visited(n,0);
        vector<int> cycle(n,0);

        for(int i=0;i<n;i++){
            if( !visited[i]){
                if(dfs(i,n,visited,cycle,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};