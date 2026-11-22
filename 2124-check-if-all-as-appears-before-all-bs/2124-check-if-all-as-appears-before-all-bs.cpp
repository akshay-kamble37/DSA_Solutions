class Solution {
public:
    bool checkString(string s) {
        int left = 0;
        while(s[left] == 'a'){
            left++;
        }
        for(int i = left ; i < s.size() ; i++){
            if(s[i] == 'a') return false;
        } 
        return true;
    }
};