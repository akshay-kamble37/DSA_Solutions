class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        string ans = "";
        for(int i=0;i<num.size();i++){
            while(! ans.size() == 0 && ans.back() > num[i] && k != 0){
                ans.pop_back();
                k--;
            }
            if(num[i] != 0){
                ans.push_back(num[i]);
            }
        }
        while(k!= 0 ){
            ans.pop_back();
            k--;
        }
        int left = 0 ;
        num = "";
        while(ans[left] == '0'){
            left++;
        }
        num = ans.substr(left,ans.size() - left +1);
        
        return num.size()!=0?num:"0";
    }
};