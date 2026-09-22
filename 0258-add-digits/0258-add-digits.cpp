class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int sum = 0 ;
            int n = num;
            while(n > 0){
                int l = n%10;
                n = n/10;
                sum += l;
            }
            num = sum;
        }
        return num;
    }
};