/*
  A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

 

Example 1:

Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
Example 2:

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.
  */

//Approach 1 Brute Force
// TC: O(N^2) SC:O(1)

class Solution {
public:
    string longestPrefix(string s) {
        if(s=="")
        return "";
          int n=s.length();
          int maxlen=0;

        //iterate over length of prefix and suffix 
        for(int len=1;len<n;len++){
            bool isEqual=true;
            // Compare prefix and suffix
            for(int i=0;i<len;i++){
               if(s[i]!=s[n-len+i]){
                isEqual=false;
                break;
               }    
            }
            if (isEqual) {
                maxlen = len;
            }
             
         
        }
        return s.substr(0,maxlen);
    }
};

//Approach 2 : 
// TC : O(N)  SC: O(N)
class Solution {
public:
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        int pre=0,suf=1;
        while(suf<n){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else{
                pre=lps[pre-1];
                }
            }

        }
        int maxlen=lps[n-1];
        return s.substr(0,maxlen);
    }
};
