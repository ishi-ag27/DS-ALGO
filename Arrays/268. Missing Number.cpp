/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
Example 2:

Input: nums = [0,1]
Output: 2
Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

*/

//Aprroach 1 : Brute Force
//Time Complexity O(n^2)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
      for(int i=0;i<=n;i++){
            int flag=0;
            for(int j=0;j<n;j++){
                if(nums[j]==i){
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            return i;
      }
       return -1;
    }
};


//Approach 2 : Better Solution - Hashing

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        vector<int>hash(n+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]=1;
        }
        for(int i=0;i<=n;i++){
            if(hash[i]==0)
                return i;
        }
        return -1;
    }
};

//Approach 3 SUM
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        long long sum1=(n*(n+1))/2;
        long long sum2=0;
        for(int i=0;i<n;i++){
            sum2+=nums[i];
        }
        return sum1-sum2;
    }
};

//Time Complexity - O(N)
//Space Complexity - O(1)

//Approach 4 XOR 
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int xor1=0,xor2=0;
       for(int i=0;i<=n-1;i++){
           xor2=xor2^nums[i];
           xor1=xor1^i;
       }
       xor1=xor1^n;
       return xor1^xor2;
    }
};
//Time Complexity - O(N)
//Space Complexity - O(1)
