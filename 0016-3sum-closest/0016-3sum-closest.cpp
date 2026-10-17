class Solution {

struct Compare{
    bool operator()(pair<int,int> a,pair<int,int> b){
        return a.second > b.second;
    }
};

public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - ans)) {
                    ans = sum;
                }

                if (sum == target) {
                    return sum;
                } 
                else if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return ans;
    }
};