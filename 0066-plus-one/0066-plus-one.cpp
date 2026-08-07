class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(n == 0) return digits;
        if(digits[n-1] < 9){
            digits[n-1]+=1;
            return digits;
        }

        int last = 1;
        int carry = 1;
        digits[n-1] = 0 ;
        for(int i=n-2;i>=0;i--){
            if(digits[i] == 9 && carry == 1){
                carry = 1;
                digits[i] = 0;
            }else if(carry == 1){
                digits[i] += 1;
                carry = 0;
            }else{
                return digits;
            }
        }
        if(carry == 1){
            digits[0] = 1;
            digits.push_back(0);
        }

        return digits;
    }
};