#include<iostream>
using namespace std;
#include<vector>


void bubbleSort(vector<int>&a,int n){
   for(int i=n-1;i>=1;i--){
       int didSwap=0;
       for(int j=0;j<=i-1;j++){
           if(a[j]>a[j+1]){
               swap(a[j],a[j+1]);
               didSwap=1;
           }
       }
       if(didSwap==0){
           break;
       }
   }
}

int main(){
    vector<int>arr={4,6,2,5,7,9,1,3};
    int n=arr.size();
    bubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
