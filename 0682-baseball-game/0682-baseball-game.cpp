class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(int i=0;i<ops.size();i++){
            if(ops[i] == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                int third = first + second;
                st.push(first);
                st.push(third);
            }else if(ops[i] == "D"){
                st.push(st.top() * 2);
            }else if(ops[i] == "C"){
                st.pop();
            }else{
                int num = stoi(ops[i]);
                st.push(num);
            }
        }
        int num = 0 ;
        while( ! st.empty()){
            num += st.top();
            st.pop();
        }
        return num;
    }
};