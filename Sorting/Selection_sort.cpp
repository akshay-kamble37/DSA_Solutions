/* SELECTION SORT 

Selection sorting is a simple sorting method 
that repeatedly selects the minimum element 
from the unsorted part and places it at the correct position.

Approach-
- It divides the array into sorted and unsorted parts
- Initially, the entire array is unsorted
- Find the smallest element from the unsorted part
- Swap it with the first element of the unsorted part
- Move the boundary of sorted part forward
- Repeat until the array is sorted

- Requires nested loop

- Time Complexity 
        Best case  - O(n^2)
        Average case - O(n^2)
        Worst case - O(n^2)

- Space Complexity:
        - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={18,6,12,42,36,30,0};
    int length=sizeof(arr)/sizeof(arr[0]);
    int point =-1;
    while(point < length){
        int smallest=point+1;
        for(int i=point+1;i<length;i++){
            if(arr[smallest] > arr[i]){
                smallest = i;
            }
        }
        point++;
        swap(arr[smallest],arr[point]);
    }
    for(int i=0;i<length;i++){
        cout<<arr[i]<<" ";
    }
}
