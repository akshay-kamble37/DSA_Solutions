//Problem : Generate Binary Strings without Consecutive 0's
//Difficulty: Medium
//Platform : Leetcode / GFG


/*Approach (Backtracking - Constraint Based):

Step 1 : Start with an empty string

Step 2 : At each index, try to add '1'
         - Always allowed
         - Push '1', recurse, then backtrack

Step 3 : Try to add '0' only if:
         - String is empty OR last character is '1'
         - This avoids consecutive '0's

Step 4 : Base Case:
         - If i == n → store the string

Step 5 : Continue until all valid strings are generated


Time Complexity :
- O(2^n) (pruned search space)

Space Complexity :
- O(n) (recursion stack)

*/
class Solution {
public:
    void Generator(string &s,int i,int n,vector<string> &result){
        if(i == n){
            result.push_back(s);
            return ;
        }

        s.push_back('1');
        Generator(s,i+1,n,result);
        s.pop_back();

        if(s.empty() || s.back() == '1'){
            s.push_back('0');
            Generator(s,i+1,n,result);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        string s="";
        vector<string> result;
        Generator(s,0,n,result);
        return result;
    }

};