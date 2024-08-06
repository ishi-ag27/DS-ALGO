/*
  
  Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

  */

//Approach 1 TC:O(N^2)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=n-m;i++){
            int first=i;
            int second=0;
            while(second<m){
                if(haystack[first]!=needle[second]){
                    break;
                }
                else{
                    first++;
                    second++;
                }
            }
            if(second==m){
                return first-second;
            }
        }
        return -1;
    }
};

//Approach 2 KMP algorithm
//TC : O(m)+O(n) 
//SC: O(m)
class Solution {
public:
    void lpsfind(vector<int>&lps,string s){
        int n=s.size();
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
        
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int>lps(m,0);
        lpsfind(lps,needle);
        int first=0,second=0;
        while(second<m && first<n){
            if(needle[second]==haystack[first])
           { first++;
            second++;
        }
        else{
        
            if(second==0){
                first++;
            }
            else{
                second=lps[second-1];
            }
        }
        }
    if(second==m){
        return first-second;
    }
    else{
        return -1;
    }
    }
};
