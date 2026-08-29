class Solution {
public:
    int subtractProductAndSum(int n) {
        int a = n;
        long long sum = 0;
        long long prod=1;
        while(a>0){
            int b = a%10;
            a =a/10;
            sum += b;
            prod *= b;
        }
        return prod-sum;
    }
};