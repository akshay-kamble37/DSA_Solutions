//Problem : Generate Parentheses (All Valid Combinations)
//Difficulty: Medium
//Platform : Leetcode


/*Approach (Backtracking with Constraints):

Step 1 : Use recursion to build the string step by step

Step 2 : Maintain two counters:
         - open  → number of '(' used
         - close → number of ')' used

Step 3 : At each step, we have two choices:

         Choice 1 → Add '('
         - Allowed only if open < n
         - Increment open count

         Choice 2 → Add ')'
         - Allowed only if close < open
         - Ensures validity (no extra closing bracket)

Step 4 : Base Case:
         - If string length == 2*n
         - Store the valid string in result

Step 5 : Backtrack after each recursive call


Time Complexity :
- O(2^n) (approx)
- Actually closer to Catalan number → O(4^n / √n)

Space Complexity :
- O(n)
- Due to recursion stack (excluding output)

*/


class Solution {
public:
    void subset(vector<int> &nums,int i,vector<int> &current,vector<vector<int>> &result){
        if(i == nums.size()){
            result.push_back(current);
            return;
        }
        subset(nums,i+1,current,result);
        
        current.push_back(nums[i]);
        subset(nums,i+1,current,result);
        current.pop_back();
    
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        subset(nums,0,current,result);

        return result;
    }
};