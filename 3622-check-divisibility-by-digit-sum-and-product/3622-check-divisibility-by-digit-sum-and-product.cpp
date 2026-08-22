class Solution {
public:
    bool checkDivisibility(int n) {
        int a = n;

        int sum = 0;
        int prod = 1;
        while(a != 0){
            int b = a%10;
            a = a/10;

            sum += b;
            prod *= b;
        }
        return (n % (sum + prod) == 0) ? true : false ; 
    }
};