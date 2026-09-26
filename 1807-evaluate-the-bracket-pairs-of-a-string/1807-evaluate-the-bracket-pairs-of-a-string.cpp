class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
         unordered_map<string, string> mp;

        // Store key-value pairs
        for (auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string result;
        int i = 0;

        while (i < s.length()) {

            if (s[i] == '(') {
                int j = i + 1;

                // Find closing bracket
                while (s[j] != ')') {
                    j++;
                }

                // Extract key
                string key = s.substr(i + 1, j - i - 1);

                // Replace with value or '?'
                if (mp.find(key) != mp.end()) {
                    result += mp[key];
                } else {
                    result += '?';
                }

                i = j + 1;
            }
            else {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};