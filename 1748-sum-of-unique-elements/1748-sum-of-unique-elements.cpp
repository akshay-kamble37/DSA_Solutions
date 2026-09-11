class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]] += 1;
        }
        int sum = 0;
        for(auto val:mp){
            if(val.second < 2) sum+=val.first;
        }
        return sum;
    }
};