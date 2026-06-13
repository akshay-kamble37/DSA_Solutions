//Problem : Combination Sum III (Find k numbers that sum to n)
//Difficulty: Medium
//Platform : Leetcode


/*Approach (Backtracking / Pick - Not Pick):

Step 1 : Use a fixed array of numbers from 1 to 9
         - Each number can be used only once

Step 2 : At each index, we have two choices:
         - Pick the current number
         - Do NOT pick the current number

Step 3 : If we PICK:
         - Add number to current combination
         - Add its value to sum
         - Move to next index (i+1)

Step 4 : If we DO NOT PICK:
         - Simply move to next index (i+1)

Step 5 : Base Case:
         - If:
             current.size() == k AND sum == n
           → store the combination

Step 6 : Pruning:
         - If current.size() > k → stop
         - If sum > n → stop
         - If index reaches end → stop

Step 7 : Backtracking:
         - Remove last element after recursive call
         - Restore sum


Time Complexity :
- O(2^9) ≈ O(1)
- Because only numbers 1 to 9 are used

Space Complexity :
- O(k) recursion depth
- O(result) for storing combinations

*/

class Solution {
public:
    void calculate(vector<int> &number,int i,int sum,int k,int n,vector<int> &current,vector<vector<int>> &result){
        if(current.size() >= k || sum >= n || i==number.size()){
            if(current.size() == k && sum == n){
                result.push_back(current);
            }
            return;
        }
        sum+= number[i];
        current.push_back(number[i]);
        calculate(number,i+1,sum,k,n,current,result);
        sum-= number[i];
        current.pop_back();

        calculate(number,i+1,sum,k,n,current,result);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> number = {1,2,3,4,5,6,7,8,9};
        int sum=0;
        vector<int> current;
        vector<vector<int>> result;
        calculate(number,0,sum,k,n,current,result);

        return result;
    }
};