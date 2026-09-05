class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return nums;
        int left = 0;
        int right =n-1;
        while(left < right){
            if(nums[left] % 2 != 0){
                swap(nums[left],nums[right]);
                right--;
            }else left++;
        }
        return nums;
    }
};