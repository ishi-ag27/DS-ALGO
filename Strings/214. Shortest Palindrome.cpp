/*
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
*/

//Approach via KMP 
//TC: O(N)
//SC: O(N)

class Solution {
public:
    void findlps(vector<int>&lps,string s){
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
    }
    string shortestPalindrome(string s) {
        if(s=="")
        return "";

        string t=s;
        reverse(s.begin(),s.end());
        t+="$";
        t+=s;
        reverse(s.begin(),s.end());
        vector<int>lps(t.size(),0);
        findlps(lps,t);
        int matched=lps[t.size()-1];
        string appendChars=s.substr(matched);
        reverse(appendChars.begin(),appendChars.end());
        return appendChars+s;

    }
};
