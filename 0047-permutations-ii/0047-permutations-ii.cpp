class Solution {
public:
    void permute(vector<int> &nums,vector<int> &seen,vector<int> &temp,vector<vector<int>> &answer){
        if(nums.size() == temp.size()){
            answer.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(seen[i]==1) continue;
            if(i>0 && !seen[i-1] && nums[i] == nums[i-1]) continue;
            seen[i] = 1;
            temp.push_back(nums[i]);
            permute(nums,seen,temp,answer);
            seen[i] = 0;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> answer;
        vector<int> seen(nums.size(),0);
        permute(nums,seen,temp,answer);

        return answer;
    }
};