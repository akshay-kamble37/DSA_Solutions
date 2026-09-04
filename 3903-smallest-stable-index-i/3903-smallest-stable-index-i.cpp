class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN ; 
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            ans[i] = maxi;
        }
        int mini = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mini = min(mini,nums[i]);
            ans[i] -= mini;
        }
        int index = -1;
        for(int i=0;i<n;i++){
            if(ans[i] <= k) return i;
        }
        return index;

    }
};