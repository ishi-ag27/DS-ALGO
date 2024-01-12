class Solution {
public:
    /*TOP DOWN- Add memoization to recursion
    int solve(vector<int>&cost,int n,vector<int>&dp){
        if(n==0)
        return cost[0];
        if(n==1)
        return cost[1];
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
    Bottom Up DP - Convert recursion to iteration
      int solve(vector<int>&cost,int n){
          vector<int>dp(n);
          dp[0]=cost[0];
          dp[1]=cost[1];

          for(int i=2;i<n;i++){
               dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
          }
       
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=solve(cost,n);
        return ans;
    }
    */
    /* Fine Tuning - Reduce O(n) space to O(1)*/
    int solve(vector<int>&cost,int n){
        int prev2=cost[0];
        int prev1=cost[1];
        for(int i=2;i<n;i++){
           int  curr=min(prev1,prev2)+cost[i];
            prev2=prev1;
            prev1=curr;
        }
        return(min(prev1,prev2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int ans=solve(cost,n);
        return ans;
    }
};
