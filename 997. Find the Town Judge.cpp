class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int i,m;
        m=trust.size();
       vector<int>a(n+1,0);
       for(i=0;i<m;i++)
       {
           a[trust[i][0]]--;
           a[trust[i][1]]++;
       }
       for(i=1;i<=n;i++)
       {
           if(a[i]==n-1)
           return i;
       }
       return -1;
    }
};
