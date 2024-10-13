#include<iostream>
using namespace std;
#include<vector>

int qs(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j)
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    
    return j;
    
}

void quickSort(vector<int>&arr,int low,int high){
    //base case
    if(low>=high){
        return;
    }
    int pIndex=qs(arr,low,high);
    quickSort(arr,low,pIndex-1);
    quickSort(arr,pIndex+1,high);
}

int main(){
    vector<int>arr={4,6,2,5,7,9,1,3};
    int n=arr.size();
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
