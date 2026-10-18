class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> vec ; 

        while(k > 0){
            int digit = k%10;
            k = k/10;
            vec.insert(vec.begin(),digit);
        }
        int carry = 0;
        int first = num.size()-1;
        int second = vec.size()-1;
        vector<int> ans;
        while(first >= 0 && second >= 0){
            int add = num[first]+vec[second]+carry;
            carry = 0;
            if(add > 9 ){
                carry = 1;
                add = add%10;
                ans.insert(ans.begin(),add);
            }else{
                ans.insert(ans.begin(),add);
            }
            first--;
            second--;
        }
        while(first >= 0){
            int add = num[first]+carry;
            carry = 0;
            if(add > 9 ){
                carry = 1;
                add = add%10;
                ans.insert(ans.begin(),add);
            }else{
                ans.insert(ans.begin(),add);
            }
            first--;
        }
        while(second >= 0){
            int add = vec[second]+carry;
            carry = 0;
            if(add > 9 ){
                carry = 1;
                add = add%10;
                ans.insert(ans.begin(),add);
            }else{
                ans.insert(ans.begin(),add);
            }
            second--;
        }
        if(carry == 1){
            ans.insert(ans.begin(),1);
        }

        return ans;
    }
};


/* FAILED 

 int carry = 0;
        int n = num.size()-1;
        while(k > 0){
            int digit = k%10;
            k = k/10;

            int add = num[n] + carry + digit;
            carry = 0;
            if(add > 9){
                num[n] = add%10;
                carry = 1;
            }else{
                num[n] = add;
            }
            n--;
        }
        while(n >= 0 && carry ==1){
            int add = num[n] + carry;
            carry = 0;
            if(add > 9){
                num[n] = add%10;
                carry = 1;
            }else{
                num[n] = add;
            }
            n--;
        }
        if(carry == 1 ){
            num.insert(num.begin(),1);
        }

        return num;

*/