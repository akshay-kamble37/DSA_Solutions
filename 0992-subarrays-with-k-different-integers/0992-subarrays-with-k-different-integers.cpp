class Solution {
public:
    int fun(vector<int> &nums,int k){
        int left=0,right=0,count=0;
        map<int,int> mp;
        while(right < nums.size()){
            mp[nums[right]] += 1;
            while(mp.size() > k){
                mp[nums[left]] -= 1;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
            count+= (right - left + 1);
            right++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};