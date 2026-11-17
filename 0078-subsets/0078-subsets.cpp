class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int num = nums.size();
        num = (1<<num)-1;
        vector<vector<int>> answer;
        while(num >= 0){
            vector<int> temp;
            for(int i=0;i<nums.size();i++){
                if(num & 1<<i){
                    temp.push_back(nums[i]);
                }
            }
            answer.push_back(temp);
            num--;
        }
        return answer;

    }
};