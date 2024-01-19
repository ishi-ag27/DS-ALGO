
#include<bits/stdc++.h>

int solve(int n,vector<int>&nums){
	vector<int>dp(n+1,INT_MIN);
	dp[0]=0;

	for(int i=1;i<=n;i++){
		for(int j=0;j<nums.size();j++){
			if((i-nums[j])>=0 && (dp[i-nums[j]]!=INT_MIN)){
				dp[i]=max(dp[i],1+dp[i-nums[j]]);

			}
		}
	}
	if(dp[n]==INT_MIN)
	return -1;
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// Write your code here.
	vector<int>nums;
	
	nums.push_back(x);
	nums.push_back(y);
	nums.push_back(z);
	int ans=solve(n,nums);
	return (ans < 0) ? 0 : ans;

}
