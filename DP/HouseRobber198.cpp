class Solution {
public:
    //space optimized approach
    /*int solve(vector<int>&nums){
        int n=nums.size();
        int prev2=0;
        int prev1=nums[0];

        for(int i=1;i<n;i++){
            int incl=nums[i]+prev2;
            int excl=0+prev1;
            int ans=max(incl,excl);
            prev2=prev1;
            prev1=ans;
        }
        return prev1;

}

    int rob(vector<int>& nums) {
        return solve(nums);
    }*/
    //Tabulation approach
    int solve(vector<int>&nums){
          int n=nums.size();
        vector<int>dp(n+1,0);
        dp[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int include=nums[i]+dp[i+2];
            int exclude=0+dp[i+1];
            dp[i]=max(include,exclude);
        }
        return dp[0];


}

    int rob(vector<int>& nums) {
        return solve(nums);
    }
};
