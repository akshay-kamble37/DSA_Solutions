//Problem: Remove outermost Parenthesis
//Platform : Leetcode,GFG
//Difficulty: Easy


class Solution {
public:
    string removeOuterParentheses(string nums) {
        string solution;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count++;
            }else if(nums[i]=='(' && count!=0){
                solution.push_back(nums[i]);
                count++;
            }else if(nums[i]==')' && count-1 !=0){
                solution.push_back(nums[i]);
                count--;
            }else{
                count=0;
            }
        }
        return solution;
    }
};