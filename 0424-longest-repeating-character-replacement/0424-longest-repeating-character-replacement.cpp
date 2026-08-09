class Solution {
public:
    int characterReplacement(string s, int k) {
        set<char> st;
        for(int i=0;i<s.size();i++){
            st.insert(s[i]);
        }
        int maxi = 0;
        for(char it:st){
            queue<int> mp;
            char ch = it;
            int left =0;
            for(int right = 0; right < s.size(); right++) {

                if(s[right] != ch)
                    mp.push(right);

                if(mp.size() > k) {
                    left = mp.front() + 1;
                    mp.pop();
                }

                maxi = max(maxi, right - left + 1);
            }
        }
        return maxi;
        
    }
};