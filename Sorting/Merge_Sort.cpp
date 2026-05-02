//MERGE SORT

/*
1. Divide the Array

- Split the array into two halves using the middle index.
- Continue dividing each half recursively until each subarray contains only one element.
- A single element is always considered sorted.

2. Sort and Merge

- Start merging the smaller subarrays.
- Compare elements from both halves and place the smaller one into the original array.
- Continue this process until all elements are merged in sorted order.

3. Repeat

- Recursively divide and merge until the entire array becomes sorted.*/


class Solution {
  public:
    void merge(vector<int>& nums,int left,int mid,int right){
        int i,j,k;
        int n1=mid - left +1;
        int n2=right - mid;
        vector<int> l(n1),r(n2);
        
        for(int i=0;i<n1;i++){
            l[i]=nums[left+i];
        }
        for(int i=0;i<n2;i++){
            r[i]=nums[mid+1+i];
        }
        i=0;
        j=0;
        k=left;
        while(i<n1 && j<n2){
            if(l[i] <= r[j]){
                nums[k]=l[i];
                i++;
            }else{
                nums[k]=r[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            nums[k]=l[i];
            i++;
            k++;
        }
        while(j<n2){
            nums[k]=r[j];
            j++;
            k++;
        }
        
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        if(left<right){
            int mid = left + (right-left)/2;
            
            mergeSort(nums , left,mid);
            mergeSort(nums , mid+1, right);
            
            merge(nums,left,mid,right);
        }
    }
};