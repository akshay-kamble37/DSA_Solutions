/*You are given a string s representing an infix expression. Convert this infix expression to a prefix expression.

Infix : The expression of the form a op b. When an operator is in between every pair of operands.
Prefix : The expression of the form op a b. When an operator comes before its two operands.

Precedence Order and Associativity are as follows:

^ has the highest precedence and is evaluated from right to left.
* and / come next with left to right associativity.
+ and -  have the lowest precedence with left to right associativity.
Examples:

Input: s = "a*(b+c)/d"
Output: /*a+bcd
Explanation: The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc. Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc), so it becomes *a+bc. Finally, divide this result by d, so it becomes /*a+bcd.
Input: s = "(a-b/c)*(a/k-l)"
Output: *-a/bc-/akl
Explanation: The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.Now the expression looks like (a-/bc) * (/ak-l).Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl. Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.*/

class Solution
{
public:
    int pref(char ch)
    {
        if (ch == '^')
            return 4;
        else if (ch == '*' || ch == '/')
            return 3;
        else if (ch == '+' || ch == '-')
            return 2;
        return 1;
    }
    string infixToPrefix(string &s)
    {
        stack<char> st;
        string ans = "";
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9')
            {
                ans = s[i] + ans;
            }
            else if (s[i] == ')')
            {
                st.push(s[i]);
            }
            else if (s[i] == '(')
            {
                while (st.top() != ')')
                {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.pop();
            }
            else if (s[i] == '^')
            {
                while (!st.empty() && st.top() == '^')
                {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.push(s[i]);
            }
            else
            {
                while (!st.empty() && pref(s[i]) < pref(st.top()))
                {
                    ans = st.top() + ans;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
