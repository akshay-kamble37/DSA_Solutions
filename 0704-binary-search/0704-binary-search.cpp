class Solution {
public:
    int Recursive(vector<int>& nums,int tar,int start,int end){
        if(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==tar) return mid;
            else if(nums[mid] > tar){
                return Recursive(nums,tar,start,mid-1);
            }else{
                return Recursive(nums,tar,mid+1,end);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return Recursive(nums,target,0,nums.size()-1);
    }
};