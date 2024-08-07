/*
Problem statement
You are given a string 'S' of length 'N' representing an integer.



A string is a valid parenthesis if it satisfies one of the following conditions:

If the string is empty or consists of a character other than ‘(‘ and ')'.

If the string can be represented as a concatenation of two strings such that both strings are valid parentheses strings.

If the string can be represented as '(A)', where A is a valid parenthesis.


Depth of a string is defined as follows:

depth( '' )=0

depth( A )=0, where ‘A’ is an empty string or consists of a character other than ‘(‘ and ‘)’.

depth( A+B )=max(depth( A ), depth( B )), such that ‘A’ and ‘B’ are both strings are valid parentheses strings.

depth( (A) ) = 1+depth(A), where ‘A’ is a valid parentheses string.


Given a valid parentheses string ‘S’, you must return the nesting depth of the string ‘S’.



Example:

Input:
S = '1+(3*6+(9-3))', N=13
Output: 2

Explanation: The digits 9 and 3 are inside of 2 nested parentheses. Hence we return 2.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
15
(3*(4*(5*(6))))
Sample Output 1:
4
Explanation Of Sample Input 1:
Input:
S = '(3*(4*(5*(6))))', N = 15
Output: 4

Explanation: The digit 6 is inside of 4 nested parentheses. Hence we return 4.
Sample Input 2:
11
(((((5)))))    
Sample Output 2:
5
Constraints:
1 <= N <= 10^5
’S’ consist of digits from 0 to 9 and characters ‘+’, ‘-’, ‘*’, ‘/’, ‘(’ and ‘)’.

Time Limit: 1 sec
Follow Up:
Can you solve this in O(N) time?


*/
class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int res=0;
        for(char &ch:s){
            if(ch=='('){
                depth++;
            }
            else if(ch==')'){
                depth--;
            }
            res=max(res,depth);
        }
        return res;
    }
};
