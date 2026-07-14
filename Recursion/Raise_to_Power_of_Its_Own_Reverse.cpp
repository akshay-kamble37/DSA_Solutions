//Problem : Reverse Exponentiation
//Difficulty: Medium
//Platform : GeeksforGeeks


/*Approach (Reverse Number + Fast Exponentiation):

Step 1 : Store the original number
         - Save the given number `n` in variable `a`
         - This will be the base of exponentiation

Step 2 : Reverse the number
         - Extract digits using `% 10`
         - Build the reversed number digit by digit
         - Example:
             n = 12
             reversed = 21

Step 3 : Apply Fast Exponentiation (Binary Exponentiation)
         - Compute a^(reversed)
         - Use recursion to reduce the exponent by half each time

Step 4 : Recursive Base Case
         - If exponent becomes 0, return 1
         - Since any number raised to power 0 is 1

Step 5 : Divide and Conquer
         - Recursively calculate power(base, exponent/2)
         - Store the result in `half`

Step 6 : Compute Result
         - If exponent is even:
             result = half × half
         - If exponent is odd:
             result = half × half × base

Step 7 : Return Final Answer
         - Return a^(reverse(n))


Time Complexity :
- Reversing the number : O(d)
  (d = number of digits)
- Fast Exponentiation : O(log reverse(n))
- Overall : O(d + log(reverse(n)))

Space Complexity :
- O(log reverse(n))
  (Recursive call stack)

*/

class Solution {
  public:
    int power(int p,int ans){
        
        if(ans == 0) return 1;
        
        int half = power(p,ans/2);
        
        if(ans%2 == 0){
            return half*half;
        }else{
            return half*half*p;
        }
    }  
      
    int reverseExponentiation(int n) {
        int a = n;
        int ans=0;
        while(n/10 > 0){
            int b= n%10;
            ans = (ans * 10 ) + b;
            n = n/10;
        }
        ans = (ans * 10 ) + n;
        
        int answer = power(a,ans);
        return answer;
    }
};