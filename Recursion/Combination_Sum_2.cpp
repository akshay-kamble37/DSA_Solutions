//Problem : Combination Sum II (Unique combinations, each element used once)
//Difficulty: Medium
//Platform : Leetcode


/*Approach (Backtracking with Loop + Duplicate Handling):

Step 1 : Sort the array
         - Required to handle duplicates efficiently
         - Helps in pruning (early stopping)

Step 2 : Use backtracking with a loop
         - Iterate from current index `i` to end

Step 3 : At each step:
         - Pick the current element
         - Move to next index (j+1) → ensures element is used only once

Step 4 : Skip duplicates:
         - If current element is same as previous (at same level), skip it
         - Condition: if(j > i && candidates[j] == candidates[j-1]) continue;

Step 5 : Pruning:
         - If sum + current element > target → break loop
         - Because array is sorted

Step 6 : Base Case:
         - If sum == target → store current combination and return

Step 7 : Backtracking:
         - Add element before recursion
         - Remove after recursion


Time Complexity :
- O(2^n) (worst case)
- Reduced significantly due to pruning and duplicate skipping

Space Complexity :
- O(n) recursion depth
- O(result) for storing combinations

*/

class Solution {
public:
    void combination(vector<int> &candidates,int i,int sum,vector<int> &current,vector<vector<int>> &result,int &target){
        if(sum == target){
            result.push_back(current);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if( j > i && candidates[j] == candidates[j-1]) continue;

            if(sum + candidates[j] > target) break;

            current.push_back(candidates[j]);
            sum += candidates[j];
            combination(candidates,j+1,sum,current,result,target);
            current.pop_back();
            sum -= candidates[j];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        int sum =0;
        
        combination(candidates,0,sum,current,result,target);

        return result;
    }
};