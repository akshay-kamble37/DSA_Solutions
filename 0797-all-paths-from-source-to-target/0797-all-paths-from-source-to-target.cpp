class Solution {
public:
    void traverse(int node,int n,vector<vector<int>>& adj,vector<int>& path,vector<vector<int>>& ans){
        if(node == n){
            ans.push_back(path);
            path.pop_back();
            return ;
        }

        for(auto it:adj[node]){
            path.push_back(it);
            traverse(it,n,adj,path,ans);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;

        int n = graph.size();

        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(auto it : graph[i]){
                adj[i].push_back(it);
            }
        }

        vector<int> path;
        path.push_back(0);
        traverse(0,n-1,adj,path,ans);

        return ans;

    }
};

/* APPROACH 

APPLYING DFS -- 

TRAVERSING EACH NODE BY USING THE RECURSION 

*/