class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi =0 ;
        maxi = *max_element(nums.begin(),nums.end());
        int count = 0 ;
        for(int it:nums){
            count += maxi - it;
        }
        return count;
    }
};