/* BUBBLE SORT 

Bubble sorting is a sorting method 

Approach- It compares pair in each pass
- if the left element is greater than right element then swaps happen 
- if the left element is smaller than right elemnt then iterator moves forward
- requires nested loop

- Time Complexity 
        Best case- O(n)
        Worst Case -O(n^2)
    
-Space Complexity:
        - o(1)
*/


#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
    int array[5]={10,5,15,20,0};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(array[j] > array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
    for(int i=0;i<5;i++){
        cout<<array[i]<<" ";
    }
}