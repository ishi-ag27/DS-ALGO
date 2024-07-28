/*921. Minimum Add to Make Parentheses Valid

A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 */

class Solution {
public:
    int minAddToMakeValid(string s) {
        //odd condition
        if(s.length()%2==1){
            return -1;
        }
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch=='('){
                st.push(ch);
            }
            else{
                //ch is a close bracket
                if(!st.empty()&& st.top()=='('){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
        }
        //stack contains invalid expression now
        int a=0,b=0;
        while(!st.empty()){
            if(st.top()=='('){
                b++;
            }
            else{
                a++;
            }
            st.pop();
        }
        int ans=((a+1)/2)+((b+1)/2);
        return ans; 
    }
};
