
/* ### Approach:

1. **Dynamic Programming Bottom UP Approach**
   - Create a 2D DP table to store whether substrings are palindromes.
   - Initialize DP table for substrings of length 1 and 2, as they are base cases.
   - For substrings of length 3 and more, use the result of smaller substrings to determine if the current substring is a palindrome.
   - Keep track of the longest palindromic substring found during the process.

2. **Initialization:**
   - Set DP values for substrings of length 1 (single characters) to true, as they are always palindromes.
   - Set DP values for substrings of length 2 to true if the characters at both ends are the same.

3. **Transition and Update:**
   - Iterate over all possible substring lengths (starting from 3) and update the DP table based on the results of smaller substrings.
   - If the current substring is a palindrome, update the DP table and check if it is longer than the current longest palindromic substring.

4. **Result:**
   - Return the longest palindromic substring found.

### Intuition:

The approach uses dynamic programming to build up solutions for smaller substrings and uses those results to efficiently find the longest palindromic substring. By breaking the problem into smaller subproblems, the solution avoids redundant computations and achieves better time complexity.

### Time Complexity:

- The nested loops iterate over all substrings, resulting in a time complexity of O(n^2), where n is the length of the input string.
- Filling in the DP table for each substring takes constant time.

The overall time complexity is O(n^2).

### Space Complexity:

- The DP table has a space complexity of O(n^2) since it stores results for all possible substrings.
- Additional variables (`maxlen` and `sp`) have constant space complexity.

The overall space complexity is O(n^2).

### Code:

*/
#include <vector>
#include <string>


  class Solution {
public:
    bool isPalindrome(vector<vector<bool>>& dp, string& s, int l, int r) {
        if (l == r)
            return true;
        else if (r - l == 1)
            return s[l] == s[r];
        else
            return dp[l + 1][r - 1] && s[l] == s[r];
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        int sp = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // Check all substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                maxlen = 2;
                sp = i;
            }
        }

        // Check substrings of length 3 and more
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (isPalindrome(dp, s, i, j)) {
                    dp[i][j] = true;
                    if (len > maxlen) {
                        maxlen = len;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxlen);
    }
};

/* Approach 2 : Recursion+Memoization :
Let's analyze the time and space complexity of the given code:

### Time Complexity:

1. **Nested Loops:**
   - The nested loops iterate over all possible substrings, considering each pair of indices `i` and `j`.
   - The `solve` function is called for each pair, and its time complexity is O(1) in the best case and O(j-i+1) in the worst case.
   - The overall time complexity is dominated by the nested loops, resulting in O(n^3), where `n` is the length of the input string.

### Space Complexity:

1. **DP Table:**
   - The `t` array is used for memoization. Its size is `1001 x 1001`, and it stores boolean values.
   - The space complexity for the `t` array is O(1001 * 1001), which is essentially O(1) considering it's a constant-size array.

2. **Other Variables:**
   - Other variables (`n`, `maxlen`, `sp`, `i`, `j`) use constant space, so they don't contribute significantly to the overall space complexity.

The overall space complexity is dominated by the memoization table and is O(1) in this context.

### Summary:

- Time Complexity: O(n^3)
- Space Complexity: O(1)
*/
class Solution {
public:
  int t[1001][1001];
  bool solve(string &s,int i,int j){
      if(i>=j){
          return 1;
      }
      if(t[i][j]!=-1){
          return t[i][j];
      }
      if(s[i]==s[j])
      return t[i][j]=solve(s,i+1,j-1);

      return t[i][j]=0;
  }
  string longestPalindrome(string s){
      int n=s.length();
      memset(t,-1,sizeof(t));
      int maxlen=INT_MIN;
      int sp=0;

      for(int i=0;i<n;i++){
          for(int j=i;j<n;j++){
              if(solve(s,i,j)==true){
                  if(maxlen<j-i+1){
                      maxlen=j-i+1;
                      sp=i;

                  }
              }
          }
      }
      return s.substr(sp,maxlen);
  }

};
