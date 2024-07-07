/* Problem statement
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

For Example :
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
  */

//Approach 1 Memoization
//TC: O(N*K) SC:O(N*K)+O(N)

#include <bits/stdc++.h> 

bool f(int ind,int k,vector<int>&arr, vector<vector<int>>&dp){
    if(k==0) return true;
    if(ind==0) return (arr[0]==k);

    if(dp[ind][k]!=-1) return dp[ind][k];

    bool notTake=f(ind-1,k,arr,dp);
    bool take=false;
    if(arr[ind]<=k){
        take=f(ind-1,k-arr[ind],arr,dp);

    }
    return dp[ind][k]=take||notTake;

}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

//Approach 2 : Tabulation 
////TC: O(N*K) SC:O(N*K)
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

  //Base case: if target sum is 0
  for(int i=0;i<n;i++){
      dp[i][0]=true;
  }
  //Base case: If first element of arr is less than or equal to k,set dp[0][arr[0]] to true
  if(arr[0]<=k){
      dp[0][arr[0]]=true;
  }
  //Fill the dp array iteratively
  for(int ind=1;ind<n;ind++){
      for(int target=1;target<=k;target++){
          bool notTake=dp[ind-1][target];
          bool take=false;
          if (arr[ind] <= target) {

            take = dp[ind - 1][target - arr[ind]];
          }
          dp[ind][target]=notTake||take;
      }
  }
  return dp[n-1][k];
}

//Aproach 3 Space optimization
// TC: O(N*K)  SC: O(K)
#include <bits/stdc++.h>

bool subsetSumToK(int n, int k, vector<int> &arr) {
  vector<bool>prev(k+1,false);
  prev[0]=true;
  if(arr[0]<=k){
      prev[arr[0]]=true;
  }
  for(int ind=1;ind<n;ind++){
      vector<bool>curr(k+1,false);
      curr[0]=true;
      for(int target=1;target<=k;target++){
          bool notTake=prev[target];
          bool take=false;
          if(arr[ind]<=target){
              take=prev[target-arr[ind]];
          }
          curr[target]=take||notTake;

      }
      prev=curr;
  }
  return prev[k];
}
