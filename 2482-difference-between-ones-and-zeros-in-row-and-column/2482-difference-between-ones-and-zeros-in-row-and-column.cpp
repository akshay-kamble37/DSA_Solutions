class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>> row;

        for(int i=0;i<n;i++){
            int one = 0;
            int zero = 0;
            for(int j=0;j<m;j++){
                (grid[i][j] == 1) ? one++ : zero++; 
            }
            pair<int,int> p = {one,zero};
            row.push_back(p);
        }

        vector<pair<int,int>> col;

        for(int i=0;i<m;i++){
            int one = 0;
            int zero = 0;
            for(int j=0;j<n;j++){
                (grid[j][i] == 1) ? one++ : zero++; 
            }
            pair<int,int> p = {one,zero};
            col.push_back(p);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                auto r = row[i];
                auto c = col[j];
                grid[i][j] = (r.first - r.second) + (c.first - c.second); 
            }
        }

        return grid;

    }
};