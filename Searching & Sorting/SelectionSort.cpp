#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int mini=i;
       for(int j=i;j<n;j++){
           if(arr[j]<arr[mini]){
               mini=j;
           }
       }
        swap(arr[mini],arr[i]);
    }
    
}
int main(){
    int n=5;
    int arr[n]={3,45,2,1,9};
    selectionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
