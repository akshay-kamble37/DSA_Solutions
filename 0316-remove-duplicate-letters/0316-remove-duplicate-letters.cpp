class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);
        string st = "";

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        for (char c : s) {
            freq[c - 'a']--;

            // Character already present: skip it
            if (visited[c - 'a']) {
                continue;
            }

            // Remove larger characters if they appear again later
            while (!st.empty() && st.back() > c &&
                   freq[st.back() - 'a'] > 0) {
                visited[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            visited[c - 'a'] = true;
        }
        return st;

    }
};