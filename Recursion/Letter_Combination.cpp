// Problem   : Letter Combinations of a Phone Number
// Difficulty: Medium
// Platform  : LeetCode


/* Approach (Backtracking)

Step 1 : Create the keypad mapping
         - Store the corresponding characters for each digit.
         - Example:
             2 -> "abc"
             3 -> "def"
             4 -> "ghi"
             5 -> "jkl"
             6 -> "mno"
             7 -> "pqrs"
             8 -> "tuv"
             9 -> "wxyz"

Step 2 : Start Backtracking
         - Begin from the first digit (index = 0).
         - For the current digit, iterate through all its possible letters.

Step 3 : Choose
         - Append the current letter to the temporary string.

Step 4 : Explore
         - Recursively process the next digit (index + 1).

Step 5 : Backtrack
         - Remove the last appended letter.
         - Try the next possible letter for the current digit.

Step 6 : Base Case
         - If all digits are processed (index == digits.length()),
           the temporary string represents one valid combination.
         - Store it in the answer vector.


Time Complexity:
- Let n = number of digits.
- Each digit has at most 4 possible letters.
- Total combinations = O(4^n).
- Each combination has length n.

=> Time Complexity = O(4^n × n)

Space Complexity:
- Recursion stack = O(n)
- Temporary string = O(n)

=> Auxiliary Space = O(n)
=> Including output = O(4^n × n)
*/

class Solution {
public:
    void calculate(string nums,int i,string &temp,vector<string> &store,vector<string> &answer){
        if(i == nums.size()){
            answer.push_back(temp);
            return;
        }
        string here=store[i];
        for(int j=0;j<here.size();j++){
            temp.push_back(here[j]);
            calculate(nums,i+1,temp,store,answer);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string nums) {
        vector<string> store;
        string temp="";
        vector<string> answer;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == '2'){
                store.push_back("abc");
            }else if(nums[i] == '3'){
                store.push_back("def");
            }else if(nums[i] == '4'){
                store.push_back("ghi");
            }else if(nums[i] == '5'){
                store.push_back("jkl");
            }else if(nums[i] == '6'){
                store.push_back("mno");
            }else if(nums[i] == '7'){
                store.push_back("pqrs");
            }else if(nums[i] == '8'){
                store.push_back("tuv");
            }else {
                store.push_back("wxyz");
            }
        }
        calculate(nums,0,temp,store,answer);

        return answer;

    }
};