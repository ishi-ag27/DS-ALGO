/*
Given 2 string having both uppercase and lowercase characters.Irrespective of the case determine the lexicographically smaller string return -1 if first string is smaller return 1 if second string is smaller and O if both are equal.
*/

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/



#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int compareStrings(string &str1,string &str2){
    string lowerStr1=str1;
    string lowerStr2=str2;
    
    for(char& c:lowerStr1){
        c=tolower(c);
    }
    for(char& c:lowerStr2){
        c=tolower(c);
    }
    
    if(lowerStr1<lowerStr2){
        return -1; // First string is smaller
    } 
    else if(lowerStr1>lowerStr2){
        return 1; // Second string is smaller
    }
    else {
        return 0; //Both strings are equal
    }
    
    
}


int main() {
    string str1, str2;
    
    // Input strings
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    
    // Compare the strings and output the result
    int result = compareStrings(str1, str2);
    cout << "Result: " << result << endl;
    
    return 0;
}
