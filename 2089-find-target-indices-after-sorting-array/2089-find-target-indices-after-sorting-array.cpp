class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        if(nums.size() == 0) return {};

        sort(nums.begin(),nums.end());

        int left = 0;
        int right = nums.size()-1;
        vector<int> ans;

        while(left <= right){
            int mid = left + (right-left)/2;

            if(nums[mid] == target){
                int index = mid;
                while(index >= 0 && nums[index] == target){
                    ans.insert(ans.begin(),index);
                    index--;
                }
                index = mid + 1;
                while(index < nums.size() && nums[index] == target){
                    ans.push_back(index);
                    index++;
                }
                break;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid +1  ;
            }
        }
        return ans;

    }
};


/* LINEAR SEARCH 

if(nums.size() == 0) return {};

    sort(nums.begin(),nums.end());

    vector<int> ans;
    for(int i=0;i<nums.size();i++){
        if(nums[i] == target){
            ans.push_back(i);
        }
        if(nums[i] > target) break;
    }
    return ans;

*/