class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count = 0;
        int mul=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                if(count == 1){
                    vector<int> vec(nums.size(),0);
                    return vec;
                }
                count++;
            }else{
                mul *= nums[i];
            }
        }

        for(int i=0;i<nums.size();i++){
            if(count == 1 && nums[i] != 0){
                nums[i] = 0;
            }else if(count == 0){
                nums[i] = mul/nums[i];
            }else{
                nums[i] = mul;
            }
        }
        return nums;
    }

};