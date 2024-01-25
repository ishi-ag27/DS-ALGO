class Solution {
public:
    int func(int i,int j, string &text1,string &text2,vector<vector<int>>&dp)
    {
        if(i<0 || j<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(text1[i]==text2[j])
        {
            return dp[i][j]=func(i-1,j-1,text1,text2,dp)+1;
        }
        int ans=func(i-1,j,text1,text2,dp);
        ans=max(ans,func(i,j-1,text1,text2,dp));
        
        return dp[i][j]=ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return func(text1.size()-1,text2.size()-1,text1,text2,dp);
    }
};/*
class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2,int m,int n,int memo[][1001]) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+longestCommonSubsequence(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(longestCommonSubsequence(text1,text2,m-1,n,memo),longestCommonSubsequence(text1,text2,m,n-1,memo));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        int memo[1001][1001];
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                memo[i][j]=-1;
            }
        }
        return longestCommonSubsequence(text1,text2,m,n,memo);
    }
};*/
