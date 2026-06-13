//Problem : Subsets II (Generate all subsets without duplicates)
//Difficulty: Medium
//Platform : Leetcode


/*Approach (Backtracking with Loop + Duplicate Handling):

Step 1 : Sort the array
         - Required to group duplicates together
         - Helps in skipping duplicate subsets

Step 2 : Use backtracking with a loop
         - Start from index `i`
         - At each level, iterate through remaining elements

Step 3 : Add current subset to result
         - Every state is a valid subset

Step 4 : For each element:
         - Pick the element
         - Recur for next index (j+1)
         - Backtrack

Step 5 : Skip duplicates:
         - If current element is same as previous at same level → skip
         - Condition: if(j > i && nums[j] == nums[j-1]) continue;

Step 6 : Continue until all subsets are generated


Time Complexity :
- O(2^n)
- All subsets are generated (duplicates avoided)

Space Complexity :
- O(n) recursion depth
- O(result) for storing subsets

*/

class Solution {
public:

    void Subset(vector<int> nums,int i,vector<int> &current,vector<vector<int>> &result){
        
        result.push_back(current);

        for(int j=i;j<nums.size(); j++){
            
            if( j > i && nums[j] == nums[j-1]) continue;

            current.push_back(nums[j]);
            Subset(nums,j+1,current,result);
            current.pop_back();
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> result;
        vector<int> current ;

        Subset(nums,0,current,result);

        return result;
    }
};