// Problem   : Permutations
// Difficulty: Medium
// Platform  : LeetCode/GFG


/* Approach (Backtracking with Visited Array)

Step 1 : Create a visited array
         - Maintain a vector 'status' of size n.
         - status[i] = 1 indicates that nums[i] is already
           included in the current permutation.
         - Initially, all elements are unvisited.

Step 2 : Start Backtracking
         - Begin with an empty temporary vector.
         - Iterate through every element in the array.

Step 3 : Choose
         - If the current element is not visited,
           add it to the temporary permutation.
         - Mark it as visited.

Step 4 : Explore
         - Recursively generate the remaining positions
           of the permutation.

Step 5 : Backtrack
         - Remove the last inserted element.
         - Mark it as unvisited so it can be reused
           in other permutations.

Step 6 : Base Case
         - When the temporary vector contains all n elements,
           one complete permutation is formed.
         - Store it in the answer vector.


Time Complexity:
- There are n! possible permutations.
- Copying each permutation into the answer takes O(n).

=> Time Complexity = O(n × n!)

Space Complexity:
- Visited array = O(n)
- Temporary vector = O(n)
- Recursion stack = O(n)

=> Auxiliary Space = O(n)
=> Including output = O(n × n!)
*/

class Solution {
public:
    void calculate(vector<int> &nums,vector<int> &status,vector<int> &temp,vector<vector<int>> &answer){
        if(temp.size() == nums.size()){
            answer.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(status[i] == 1){
                continue;
            }
            temp.push_back(nums[i]);
            status[i] = 1;
            calculate(nums,status,temp,answer);
            temp.pop_back();
            status[i] = 0;
        }
    } 

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> status(nums.size(),0);
        vector<vector<int>> answer;
        vector<int> temp;
        calculate(nums,status,temp,answer);

        return answer;
    }
};