class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string,int> mp;
        for(auto it : bank){
            mp[it] = 1;
        }
        if(mp.find(endGene) == mp.end()) return -1;

        queue<pair<string,int>> q;
        pair<string,int> p = {startGene,0};
        q.push(p);

        vector<char> character = {'A', 'C', 'G', 'T'};

        while( ! q.empty()){

            int size = q.size();

            for(int i=0;i<size;i++){

                auto it = q.front();
                string word = it.first;
                int level = it.second;
                q.pop();

                if(word == endGene) return level;

                for(int i=0;i<word.size();i++){
                    string change = word;
                    for(char ch : character ){
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
        return -1;
    }
};