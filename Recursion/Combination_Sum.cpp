//Problem : Combination Sum (Find all combinations that sum to target)
//Difficulty: Medium
//Platform : Leetcode


/*Approach (Backtracking / Recursion):

Step 1 : At each index, we have two choices:
         - Pick the current element
         - Do NOT pick the current element (move to next index)

Step 2 : If we PICK the element:
         - Add it to current combination
         - Add its value to sum
         - Stay on same index (i) → allows reuse of same element

Step 3 : If we DO NOT PICK:
         - Move to next index (i+1)

Step 4 : Base Case:
         - If sum == target → store current combination
         - If sum > target OR index reaches end → stop recursion

Step 5 : Backtrack:
         - Remove last added element
         - Restore sum


Time Complexity :
- Exponential (≈ O(2^n * k))
- k = average length of combination

Space Complexity :
- O(k) recursion depth
- O(result size) for storing combinations

*/


class Solution {
public:
    void calculate(vector<int> &candidates,int i,vector<int> &current,int sum,int target, vector<vector<int>> &result){
        if(sum > target || i==candidates.size()){
            if(sum == target){
                result.push_back(current);
            }
            return;
        }
        current.push_back(candidates[i]);
        sum += candidates[i];
        calculate(candidates,i,current,sum,target,result);
        current.pop_back();
        sum -= candidates[i];

        calculate(candidates,i+1,current,sum,target,result);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        int sum = 0 ;
        
        calculate(candidates,0,current,sum,target,result);
        return result;


    }
};