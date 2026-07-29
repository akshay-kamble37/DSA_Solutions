class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if(prices.size() <= 1) return prices;
        stack<int> st;
        stack<int> rev;
        vector<int> arr(prices.size(),0);
        
        for(int i=prices.size()-1;i>=0;i--){
            if(st.empty()){
                arr[i] = prices[i];
                st.push(prices[i]);
            }else{
                while(! st.empty() && st.top() > prices[i]){
                    st.pop();
                }
                if(st.empty()){
                    arr[i]=prices[i];
                    st.push(prices[i]);
                }else{
                    arr[i] = prices[i] - st.top();
                    st.push(prices[i]);
                    while(! rev.empty()){
                        st.push(rev.top());
                        rev.pop();
                    }
                }
            }
        }
        return arr;

    }
};