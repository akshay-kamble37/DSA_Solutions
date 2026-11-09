class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp;
        for(auto it : wordList){
            mp[it] = 1;
        }
        if(mp.find(endWord) == mp.end()) return 0;

        queue<pair<string,int>> q;
        pair<string,int> p = {beginWord,1};
        q.push(p);

        while( ! q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                auto it = q.front();
                string word = it.first;
                int level = it.second;
                q.pop();

                if(word == endWord) return level;

                for(int i=0;i<word.size();i++){
                    string change = word;
                    for(char ch = 'a'; ch <= 'z' ; ch++ ){
                        change[i] = ch;
                        if(change == word) continue;
                        if(mp.find(change) != mp.end()){
                            q.push({change,level+1});
                            mp.erase(change);
                        }
                    }
                }
            }
        }
        return 0;
    }
};