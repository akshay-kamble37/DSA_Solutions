class Solution {
public:
    
    void max_heapify(vector<int> &nums,int size,int index){
        int largest = index;
        int left = 2*index+1;
        int right = 2*index + 2;
        
        if(left < size && nums[largest] < nums[left]){
            largest = left;
        }
        if(right < size && nums[largest] < nums[right]){
            largest = right;
        }

        if(largest != index){
            swap(nums[largest],nums[index]);
            max_heapify(nums,size,largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = n/2; i >= 0; i--){
            max_heapify(nums,n,i);
        }

        for (int t = n - 1; t > 0; t--) {
            swap(nums[0], nums[t]);
            max_heapify(nums, t, 0);
        }
        return nums;
    }
};

/* APPROACH -

step 1: Creating max heap first
step 2: Swapping the last element with the first 
- {because of the map_heap the largest element is always at first}
step 3: Applying heapify algo on each iteration

*/