class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int left = 0;
        int numone = -1;
        int numtwo = -1;
        int countone = 0;
        int counttwo = 0;
        int count = 0;
        int maxi=0;

        for(int right = 0;right<nums.size();right++){
            if(numone == nums[right]) countone++;
            else if(numtwo == nums[right]) counttwo++;
            else if(count < 2 && numone == -1){
                numone = nums[right];
                count++;
                countone++;
            }else if(count < 2 && numtwo == -1){
                numtwo = nums[right];
                count++;
                counttwo++;
            }else{
                while(left < right && countone != 0 && counttwo != 0){
                    if(nums[left] == numone) countone--;
                    else counttwo--;

                    left++;
                }
                if(countone == 0){
                    numone = nums[right];
                    countone++;
                }else{
                    numtwo = nums[right];
                    counttwo++;
                }
            }

            maxi = max(maxi , right - left +1);

        }
        return maxi;
    }
};