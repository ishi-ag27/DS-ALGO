/*
A password is said to be strong if it satisfies all the following criteria:

It has at least 8 characters.
It contains at least one lowercase letter.
It contains at least one uppercase letter.
It contains at least one digit.
It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
Given a string password, return true if it is a strong password. Otherwise, return false.

 

Example 1:

Input: password = "IloveLe3tcode!"
Output: true
Explanation: The password meets all the requirements. Therefore, we return true.
Example 2:

Input: password = "Me+You--IsMyDream"
Output: false
Explanation: The password does not contain a digit and also contains 2 of the same character in adjacent positions. Therefore, we return false.
Example 3:

Input: password = "1aB!"
Output: false
Explanation: The password does not meet the length requirement. Therefore, we return false.
 

Constraints:

1 <= password.length <= 100
password consists of letters, digits, and special characters: "!@#$%^&*()-+".
  */

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n=password.size();
        if(n<8)
        return 0;
        int l=0,u=0,dig=0,sp=0;
        string specialCharacters = "!@#$%^&*()-+";
        for(int i=0;i<n;i++){
        if(i!=0 && password[i-1]==password[i]){
            return false;
        }
        if(password[i]>=65 && password[i]<=90){
            u++;
        }
        if(password[i]>=97 && password[i]<=122){
            l++;
        }
        if(password[i]>=48 && password[i]<=57){
            dig++;
        }
        else if(specialCharacters.find(password[i]) != string::npos){
            sp++;
        }
        }
        if(l>0 && u>0 && dig>0 && sp>0){
            return true;
        }
        return false;


    }
};
