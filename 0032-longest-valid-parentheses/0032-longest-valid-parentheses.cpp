class Solution {
public:
    int longestValidParentheses(string s) {
        int maxi = 0;
        stack<pair<char,int>> st;
        for(int i = 0 ; i < s.size() ; i++){
            int count =0;
            if(st.empty()) st.push({s[i],i});
            else if(s[i] == '('){
                st.push({'(',i});
            }
            else{
                if(! st.empty() && st.top().first == '(' ){
                    st.pop();
                    if(st.empty()){
                        count = i + 1;
                    }else{
                        count = i - st.top().second ;
                    }
                }else st.push({s[i],i});
            }
            maxi = max(count,maxi);
        }
        return maxi;
    }
};