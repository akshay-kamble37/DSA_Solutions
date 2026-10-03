class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return {};
        vector<int> ans(n+1,0);
        vector<int> answer;
        for(int i=0;i<n;i++){
            if(ans[nums[i]] == 1){
                answer.push_back(nums[i]);
            }
            ans[nums[i]]+=1;
        }
        return answer;
    }
};