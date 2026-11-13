class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]] += 1;
        }
        for(int i=0;i<t.size();i++){
            mp[t[i]] -= 1;
            if(mp[t[i]] == 0) mp.erase(t[i]);
        }

        char ch = 'c';
        for(auto pair:mp){
            ch = pair.first;
            break;
        }

        return ch;
    }
};