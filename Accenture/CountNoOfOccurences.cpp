
#include <iostream>
#include<string>
using namespace std;

int countOccurences(string input1 ,int input2,string input3){
    // Ensure input1 is of length input2
    if (input1.length() != input2) {
        cout << "Error: input1 length does not match input2" << endl;
        return -1;
    }
    int count =0;
    int n=input1.length();
    int m=input3.length();
    
    for(int i=0;i<=n-m;i++){
        int j;
        for( j=0;j<m;j++){
            if(input1[i+j]!=input3[j])
                break;
        }
        
         if(j==m){
            count++;
         }

    }
    return count;
    
   
}

int main() {
    string input1 = "abcabcabc";
    int input2 = input1.length(); // Example size of input1
    string input3 = "abc";

    int result = countOccurences(input1, input2, input3);
    if (result != -1) {
        cout << "The string '" << input3 << "' appears " << result << " times in '" << input1 << "'." << endl;
    }

    return 0;
}
