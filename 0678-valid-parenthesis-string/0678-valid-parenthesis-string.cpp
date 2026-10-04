class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0 ;
        for(auto c:s){
            if(c == '('){
                low++;
                high++;
            }else if(c == ')'){
                low--;
                high--;
            }else{
                low--;
                high++;
            }
            if(high < 0) return 0;
            if(low < 0) low = 0;
        }
        return low == 0;
    }
};



/*WRONG APPROACH:

int star = 0;
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                st.push(s[i]);
            }else if(s[i] == '*'){
                star++;
            }else{
                if(st.empty() && star==0 ){
                    return false;
                }else if(!st.empty() && st.top() == '('){
                    st.pop();
                }else if(star > 0){
                    st.push(s[i]);
                }
            }
        }
        if(st.empty()) return true;
        return st.size() <= star;

*/