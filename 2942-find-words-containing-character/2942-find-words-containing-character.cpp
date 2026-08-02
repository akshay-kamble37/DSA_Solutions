class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            string num = words[i];
            for(int j=0;j<num.size();j++){
                if(num[j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;

    }
};