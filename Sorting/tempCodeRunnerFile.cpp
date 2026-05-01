#include<bits/stdc++.h>
#include<>
using namespace std;

int main(){
    int array[5]={10,5,15,20,0};
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(array[j] > array[j+1]);
            swap(array[j],array[j+1]);
        }
    }
    for(int i=0;i<5;i++){
        cout<<array[i]+" ";
    }
}