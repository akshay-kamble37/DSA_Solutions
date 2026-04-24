//Problem : Longest Palindrome in linked list
//Platform : GFG
//Difficulty: Medium


class Solution {
  public:
    string longestPalindrome(string &s) {
        // code here
        if(s.size() == 0) return "";
        string answer="";
        for(int i=0;i<s.size()-1;i++){
            int left=i;
            int right=i;
            string current="";
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                current = s.substr(left,right-left+1);
                if(current.size() > answer.size()){
                    answer=current;
                }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left >=0 && right < s.size() && s[left] == s[right]){
                current = s.substr(left,right-left+1);
                if(current.size() > answer.size()){
                    answer=current;
                }
                left--;
                right++;
            }
        }
        return answer;
        
    }
};