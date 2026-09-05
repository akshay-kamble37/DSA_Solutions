class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n,0);
        int mini = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mini = max(mini,nums[i]);
            ans[i] = mini;
        }
        mini = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini = min(mini , nums[i]);
            ans[i]-=mini;
        }
        for(int i=0;i<n;i++){
            if(ans[i] <= k ) return i;
        }
        return -1;
    }
};