class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> st;
        for(int i=temp.size()-1;i>=0;i--){
            if(st.empty()){
                st.push({temp[i],0});
                temp[i] = 0;
            }else{
                int count = 1;
                while(! st.empty() && st.top().first <= temp[i]){
                    count+= st.top().second;
                    st.pop();
                }
                if(st.empty()){
                    st.push({temp[i],0});
                    temp[i] = 0;
                }else{
                    int te = temp[i];
                    temp[i] = count;
                    st.push({te,count});
                }
            }

        }
        return temp;
    }
};