class Solution {
public:
    int romanToInt(string s) {
        int total=0;
        unordered_map<char,int> mp;
            mp['M']=1000;
            mp['D']=500;
            mp['C']=100;
            mp['L']=50;
            mp['X']=10;
            mp['V']=5;
            mp['I']=1;
        char back=s[s.size()-1];
        total=mp[back];
        if(s.size() < 2) return total;
        for(int i=s.size()-2;i>=0;i--){
            char current=s[i];
            if(mp[current] < mp[back]){
                total -= mp[current];
            }else{
                total+= mp[s[i]];
            }
            back=s[i];

        }
        return total;
    }
};