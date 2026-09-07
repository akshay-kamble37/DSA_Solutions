class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        if(grid.size() == 0) return {};
        vector<int> vec;
        int row = grid[0].size();
        for(int i=0;i<grid.size();i++){
            if(i%2 == 0){
                for(int j=0;j<grid[0].size();j+=2){
                    vec.push_back(grid[i][j]);
                }
            }else{
                int start = grid[0].size()-1;
                if(row%2 != 0) start--; 
                for(int j=start;j>=0;j-=2){
                    vec.push_back(grid[i][j]);
                }
            }
            
        }
        return vec;
    }
};