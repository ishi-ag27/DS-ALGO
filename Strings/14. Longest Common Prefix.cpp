/*Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
 
Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
*/
//Approach 1 : TC - O(nlogn*m)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        for(int i=0;i<first.length();i++){
            if(first[i]!=last[i]){
                break;
            }
            result+=first[i];
        }
        return result;
    }
};

// Approach 2 : 
// Time complexity: O(n*m)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int mini=strs[0].size();
        for(int i=0;i<n-1;i++)
        {
            int count =0;
            string string1=strs[i];
            string string2=strs[i+1];
            for(int j=0;j<min(string1.size(),string2.size());j++)
            {
                if(string1[j]==string2[j])
                    count++;
                else 
                    break;
            }
            mini=min(mini,count);
        }
        if(mini==0)
            return "";
        else 
            return (strs[0].substr(0,mini));
    }
};
