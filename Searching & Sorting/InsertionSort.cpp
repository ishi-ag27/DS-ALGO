#include<iostream>
using namespace std;

void insertionSort(int a[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && a[j-1]>a[j]){
            swap(a[j],a[j-1]);
            j--;
        }
    }
    
}
int main(){
    int n=5;
    int arr[n]={3,45,2,1,9};
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
