/*
Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */
//Approach 1 : TC: O(N^2)  SC: O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        int n=s.size();
        int len=0;
        for(int i=0;i<n;i++){
            vector<int>hash(256,0);
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1)
                break;
                len=j-i+1;
                maxlen=max(len,maxlen);
                hash[s[j]]=1;
            }
        }
        return maxlen;
    }
};
//Approach 2 
// TC: O(N) SC:O(256)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int n=s.size();
        int l=0,r=0,maxlen=0;
        while(r<n){
            if(hash[s[r]]!=-1){
                if(hash[s[r]]>=l){
                    l=hash[s[r]]+1;
                }
            }
            int len=r-l+1;
            maxlen=max(maxlen,len);
            hash[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};
