/* Given a string s representing a valid mathematical expression in prefix notation. The string consists of uppercase and lowercase English letters as operands, and the operators +, -, *, /, %, and ^.

Convert the given prefix expression into its equivalent fully parenthesized infix expression and return the resulting string.

Examples :

Input: s = "*-A/BC-/AKL"
Output: ((A-(B/C))*((A/K)-L))
Explanation: The prefix expression starts with '*', so the final operation is multiplication.
The left subexpression '-A/BC' converts to '(A-(B/C))', and the right subexpression '-/AKL' converts to '((A/K)-L)'.
Combining these two subexpressions with '*' gives the fully parenthesized infix expression: ((A-(B/C))*((A/K)-L))


Input: s = "+A*BC"
Output: (A+(B*C))

Explanation: The prefix expression starts with '+', so the final operation is addition.
The left operand is 'A', and the right subexpression '*BC' converts to '(B*C)'.
Combining them with '+' gives the fully parenthesized infix expression: (A+(B*C)) */

class Solution
{
public:
    string preToInfix(string &s)
    {
        if (s.size() == 0)
            return "";
        stack<string> ans;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
            {
                ans.push(string(1, s[i]));
            }
            else
            {
                string first = ans.top();
                ans.pop();
                string second = ans.top();
                ans.pop();
                first = '(' + first + s[i] + second + ')';
                ans.push(first);
            }
        }
        return ans.top();
    }
};