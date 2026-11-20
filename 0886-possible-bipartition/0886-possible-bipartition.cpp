class Solution {
public:
    bool dfs(int node, int color,
             vector<int>& colors,
             vector<vector<int>>& adj) {

        colors[node] = color;

        for (int nei : adj[node]) {

            if (colors[nei] == -1) {
                if (!dfs(nei, 1 - color, colors, adj))
                    return false;
            }
            else if (colors[nei] == color) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> colors(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (colors[i] == -1) {
                if (!dfs(i, 0, colors, adj))
                    return false;
            }
        }

        return true;
    }
};