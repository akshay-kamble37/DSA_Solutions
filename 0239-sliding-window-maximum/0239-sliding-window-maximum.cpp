class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        vector<int> ans(nums.size(),0);
        int pointer = 0;
        k--;
        while(pointer < nums.size()){
            int right = pointer+1;
            int left = pointer-1;
            int left_B = k;
            int right_B = k;
            ans[pointer] = nums[pointer];
            while(left > -1 && left_B > 0 && ans[left] < nums[pointer]){
                ans[left] = nums[pointer];
                left_B--;
                left--;
            }
            while(right > nums.size() && right_B > 0 && nums[right] < nums[pointer]){
                ans[left] = nums[pointer];
                right++;
                right_B--;
            }
            // if(right < nums.size()) ans[right] = nums[right];
            pointer = right;
        }
        while(k>0){
            ans.pop_back();
            k--;
        }
        return ans;

    }
};