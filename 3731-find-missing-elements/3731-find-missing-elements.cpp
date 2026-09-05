class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size() ;
        if( n == 0) return {};
        map<int,int> mp;
        sort(nums.begin(),nums.end());
        int small = nums[0];
        int large = nums[n-1];
        for(int i=0;i<n;i++){
            mp[nums[i]] = 1;
        }
        vector<int> ans;
        while(small <= large){
            if(mp.find(small) == mp.end()){
                ans.push_back(small);
            }
            small++;
        }
        return ans;
    }
};