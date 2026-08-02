class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return nums;
        int left =0 ;
        int right = 1;
        sort(nums.begin(),nums.end());
        while(right < nums.size()){
            swap(nums[left],nums[right]);
            left+=2;
            right+=2;
        }
        return nums;

    }
};