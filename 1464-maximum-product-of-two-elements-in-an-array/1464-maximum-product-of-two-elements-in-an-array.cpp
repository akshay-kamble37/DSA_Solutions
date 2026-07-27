class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxone = 0;
        int maxtwo = 0;
        for(int i=0;i<nums.size();i++){
            if(maxone < nums[i]){
                maxtwo = maxone;
                maxone = nums[i];
            }else if(maxtwo < nums[i]){
                maxtwo = nums[i];
            }
        }
        return (maxone-1)*(maxtwo-1);
    }
};