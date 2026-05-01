/* INSERTION SORT 

Approach- In this approach while traversing through array numbers are placed 
        in the non-decreasing order properly

- Starting the traverse from the 2nd place, select the current value and swap upto
        smallest element than the current value

--This method is called as Insertion with Swapping

- Time Complexity 
        Best case- O(n)
        Worst Case -O(n^2)
    
-Space Complexity:
        - o(1)
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={4,3,2,10,12,1,5,6};
    for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++){
        if(arr[i-1] > arr[i]){
            int value=arr[i];
            int j=i-1;
            while(j>=0 && arr[j] > value){
                swap(arr[j],arr[j+1]);
                j--;
            }
        }       
    }
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
}