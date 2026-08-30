class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Make minIndex the smaller index
        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        // Case 1: Delete from front
        int front = maxIndex + 1;

        // Case 2: Delete from back
        int back = n - minIndex;

        // Case 3: Delete from both sides
        int both = (minIndex + 1) + (n - maxIndex);

        return min({front, back, both});

    }
};