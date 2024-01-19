//hackerrank problem solving question 

#include <bits/stdc++.h>

using namespace std;
long mod=1e9 + 7;

long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    long a[n],b[n];
    //base case 
    a[0]=x==1?1:0;
    b[0]=x==1?0:1;
    for(int i=1;i<n;i++){
        a[i]=b[i-1]%mod;
        b[i]=((a[i-1]*(k-1))+(b[i-1]*(k-2)))%mod;
    }
    return a[n-1];
}
