class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count =0;
        int maxi = 0 ;
        queue<int> qt;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
            }else if(nums[i] == 0 && k>0){
                k--;
                count++;
                qt.push(i);
            }else{
                qt.push(i);
                count = i - qt.front() ;
                qt.pop();
            }
            maxi = max(count,maxi);
        }
        return maxi;

    }
};