//Problem : Subset Sum (Generate Sum of All Subsets)
//Difficulty: Medium
//Platform : Leetcode / GFG


/*Approach (Backtracking / Recursion):

Step 1 : At each index, we have two choices:
         - Do NOT include the current element
         - Include the current element

Step 2 : Maintain a variable `total` to store sum of current subset

Step 3 : Recursive Calls:
         - First call → exclude element
         - Second call → include element (add to total)

Step 4 : Base Case:
         - If index reaches end of array
         - Store the current sum into result

Step 5 : Backtrack:
         - Remove last element from current
         - Restore total


Time Complexity :
- O(2^n)
- Because each element has 2 choices (include/exclude)

Space Complexity :
- O(n)
- Due to recursion stack

*/

class Solution {
  public:
  
    void subset(vector<int> &nums,int i,vector<int> &current,vector<int> &result,int total){
        if(i == nums.size()){
            result.push_back(total);
            return ;
        }
        
        subset(nums,i+1,current,result,total);
        
        current.push_back(nums[i]);
        total+=nums[i];
        subset(nums,i+1,current,result,total);
        current.pop_back();
        total-=nums[i];
    }
    
    vector<int> subsetSums(vector<int>& nums) {
        // code here
        vector<int> current;
        vector<int> result;
        
        subset(nums,0,current,result,0);
        
       
        return result;
    }
};