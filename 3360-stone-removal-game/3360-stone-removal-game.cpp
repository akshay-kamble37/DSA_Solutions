class Solution {
public:
    bool canAliceWin(int n) {
        int odd = 1;
        int count = 10;
        for(int i=10;i>=0;i--){
            if(i%2 == 0){
                if( n >= i){
                    n -= i;
                }else return false;
            }else{
                if( n >= i){
                    n -= i;
                }else return true;
            }
        }
        return true;
    }
};