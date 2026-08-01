/*You are given a string s that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Examples:

Input: s = "+AB"
Output: "AB+"
Explanation: In postfix form, operands come first followed by operator.
Prefix to Infix: +AB becomes A + B
Infix to Postfix: A + B becomes AB+
Input: s = "*+ABC"
Output: AB+C*
Explanation: 
Prefix to Infix: *+ABC becomes (A + B)*C
Infix to Postfix: (A + B)*C becomes AB+C* 
Input: s = "*-A/BC-/AKL"
Output: "ABC/-AK/L-*"
Explanation:
Prefix to infix: *-A/BC-/AKL becomes (A - (B / C)) * ((A / K) - L)
Convert left part to Postfix: (A - (B / C)) becomes ABC/-
Convert right part to Postfix: ((A / K) - L) becomes AK/L-
Combine both with * to get ABC/-AK/L-*  */




class Solution {
  public:
    int pref(char &ch){
        if(ch == '^') return 4;
        else if(ch == '*' || ch == '/') return 3;
        else if(ch == '+' || ch == '-') return 2;
        return 1;
    }
    
    string preToPost(string &s) {
        stack<string> ans;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') ans.push(string(1,s[i]));
            else{
                string first = ans.top();
                ans.pop();
                string second = ans.top();
                ans.pop();
                first = '(' + first + s[i] + second + ')' ;
                ans.push(first);
            }
        }
        
        
        string st = ans.top();
        
        stack<char> ch;
        string answer="";
        
        for(int i=0;i<st.size();i++){
            if((st[i] >= 'a' && st[i] <= 'z') || (st[i] >= 'A' && st[i] <= 'Z') || (st[i]>= '0' && st[i] <= '9')){
                answer.push_back(st[i]);
            }else if(st[i] == '('){
                ch.push(st[i]);
            }else if(st[i] == ')'){
                while(ch.top() != '('){
                    answer.push_back(ch.top());
                    ch.pop();
                }
                ch.pop();
            }else{
                while(! ch.empty() && pref(st[i]) <= pref(ch.top()) && st[i] != '^' ){
                    answer.push_back(ch.top());
                    ch.pop();
                }
                ch.push(st[i]);
            }
        }
        while(! ch.empty()){
            answer.push_back(ch.top());
            ch.pop();
        }
        return answer;
        
        
    }
};