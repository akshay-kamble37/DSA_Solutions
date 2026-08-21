class Solution {
public:
    void subset(vector<int> &nums,int i,vector<int> &current,vector<vector<int>> &result,int &k){
        if(k == current.size()){
            result.push_back(current);
            return;
        }
        if (i == nums.size()) {
            return;
        }

        subset(nums,i+1,current,result,k);
        current.push_back(nums[i]);

        subset(nums,i+1,current,result,k);
        current.pop_back();
    
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n,0);
        for(int i=0;i<n;i++){
            nums[i] = i+1;
        }

        vector<vector<int>> result;
        vector<int> current;
        subset(nums,0,current,result,k);

        return result;
    }
};