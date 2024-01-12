class Solution {
public:

     int solveMem(int n,vector<int>&c){
        vector<int>dp(n+1);
        dp[0]=1;
        
     for(int i=0;i<c.size();i++){
         for(int j=c[i];j<=n;j++){
         dp[j]=dp[j]+dp[j-c[i]];
     }
     }
     
     return dp[n];
     
 }
    int change(int amount, vector<int>& coins) {
         int ans=solveMem(amount,coins);
          return ans;
    }
};
