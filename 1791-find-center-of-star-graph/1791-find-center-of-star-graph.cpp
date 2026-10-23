class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int value_one = edges[0][0];
        int value_two = edges[0][1];

        for(int i=1;i<edges.size();i++){
            if(value_one == edges[i][0]) return value_one;
            else if(value_one == edges[i][1]) return value_one;
            else if(value_two == edges[i][0]) return value_two;
            else if(value_two == edges[i][1]) return value_two;
        }
        return -1;
    }
};