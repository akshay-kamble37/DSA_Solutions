class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        for(int right = 0;right<nums.size();right++){
            if(nums[right] >= minK && nums[right] <= maxK){
                nums[right] = 1;
            }else{
                nums[right] = 0;
            }
        }
        long long left = 0;
        long long count = 0;
        long long right;
        for(right=0;right<nums.size();right++){
            if(nums[right] == 0){
                long long length = (right-1)-left+1;
                count += (length * (length + 1))/2;
                left = right+1;
            }
        }
        long long length = (right-1)-left+1;
        count += (length * (length + 1))/2;
        left = right+1;
        return count;
    }
};