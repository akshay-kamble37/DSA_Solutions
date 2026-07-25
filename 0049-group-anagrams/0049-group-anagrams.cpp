class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string orignal=strs[i];
            string st = orignal;
            sort(orignal.begin(),orignal.end());
            if(mp.find(orignal) != mp.end()){
                mp[orignal].push_back(st);
            }else{
                mp[orignal].push_back(st);
            }
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};