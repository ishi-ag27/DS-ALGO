Approaches
(Also explained in the code)

Approach 1 - Brute Force
Approach 2 - Vector
Approach 3 - Set + sum
Approach 4 - Maps
Approach 5 - XOR Operation

Approach 1(Brute Force)
Initialization:

Initialize variables dup and missing to -1. These will be used to store the duplicate and missing numbers.
Iteration through Possible Numbers:

Iterate through numbers from 1 to the length of the input array (nums).
Count Occurrences:

For each number, count the occurrences in the input array nums by iterating through it.
Identify Duplicate and Missing:

If the count is 2, set dup to the current number, indicating a duplicate.
If the count is 0, set missing to the current number, indicating a missing number.
Return Result:

After the iteration, return a vector containing the found duplicate (dup) and missing (missing) numbers.
Complexity
Time complexity:
O(n2)O(n^2)O(n 
2
 )

Space complexity:
O(1)O(1)O(1)

Code


class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int dup = -1, missing = -1;
        
        for (int i = 1; i <= nums.size(); i++) {
            int count = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == i) {
                    count++;
                }
            }
            if (count == 2) {
                dup = i;
            } else if (count == 0) {
                missing = i;
            }
        }
        
        return {dup, missing};
    }
};


Approach 2(Vector)
Array Initialization:

Initialize a vector v of size n+1 with all elements set to 0. This array will be used to keep track of the occurrences of each number.
Count Occurrences:

Iterate through the given nums array and update the count of each number in the v array.
Identify Duplicate and Missing:

Iterate through the v array.
If the count of a number is 2, it is the duplicate number.
If the count of a number is 0, it is the missing number.
Return Result:

Return a vector containing the duplicate and missing numbers.
Complexity
Time complexity:
O(n)O(n)O(n)

Space complexity:
O(n)O(n)O(n)

Code

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n =nums.size();
        vector<int>v(n+1,0);
        int missing=0,duplicate =0;
        for(int i =0;i<n;i++){
            v[nums[i]]++;
        }
        for(int i =1;i<v.size();i++){
            if(v[i]==2)duplicate = i;
            if(v[i]==0)missing = i;
        }
        return {duplicate,missing};
    }
}; 



Approach 3(Set + Sum)
Calculate Expected Sum:

Calculate the expected sum of numbers from 1 to n using the formula (n * (n + 1)) / 2. This assumes no duplicates and no missing numbers.
Calculate Array and Unique Sums:

Calculate the sum of all elements in the array (array_sum).
Use an unordered_set (s) to get the unique elements in the array and calculate their sum (unique_sum).
Find Missing and Duplicate:

The difference between the expected sum and the unique sum gives the missing number (missing).
The difference between the array sum and the unique sum gives the duplicate number (duplicate).
Return Result:

Return a vector containing the duplicate and missing numbers.
Complexity
Time complexity:
O(n)O(n)O(n)

Space complexity:
O(n)O(n)O(n)

Code


class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int actual_sum = n * (n + 1) / 2;
        int array_sum = 0;
        int unique_sum = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int a : nums) {
            array_sum += a;
        }


        for (int a : s) {
            unique_sum += a;
        }

        int missing = actual_sum - unique_sum;
        int duplicate = array_sum - unique_sum;

        return {duplicate, missing};
    }
};



Approach 4(Maps)
Create an unordered_map mp to count the occurrences of numbers from 1 to n.
Iterate through numbers in the input vector nums:
Increment the count of each number in mp.
Decrement the count of each number in mp.
Iterate through the entries in mp:
Identify the number with a count of -1 as the duplicate.
Identify the number with a count of 1 as the missing number.
Complexity
Time complexity:
O(n)O(n)O(n)

Space complexity:
O(n)O(n)O(n)

Code

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n =nums.size();
        unordered_map<int,int>mp;
        for(int i =1;i<=n;i++)mp[i]++;

        for(auto a :nums)mp[a]--;
        int duplicate  = 0,missing=0;

        for(auto a :mp){
            if(a.second == -1)duplicate = a.first;
            if(a.second == 1)missing = a.first;
        }

        return {duplicate,missing};
    }
};



Approach 5(XOR Operation)
Calculate the XOR of all numbers from 1 to n (denoted as xorAll) and the XOR of the array nums (denoted as xorArray).
XOR the xorAll and xorArray to obtain xorResult.
Find the rightmost set bit in xorResult and store it in rightmostSetBit.
Divide the numbers from 1 to n into two groups based on the rightmost set bit: xorSet for numbers with the set bit, and xorNotSet for numbers without the set bit.
XOR all numbers in nums with the rightmost set bit to find the duplicate and missing numbers.
Iterate through nums and compare each number with xorSet. If found, return {xorSet, xorNotSet}; otherwise, return {xorNotSet, xorSet}.
Complexity
Time complexity:
O(n)O(n)O(n)

Space complexity:
O(1)O(1)O(1)

Code

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;
        int xorArray = 0;

     
        for (int i = 1; i <= n; i++) {
            xorAll ^= i;
        }

        
        for (int num : nums) {
            xorArray ^= num;
        }

       
        int xorResult = xorArray ^ xorAll;

        
        int rightmostSetBit = xorResult & -xorResult;

        int xorSet = 0;
        int xorNotSet = 0;

        
        for (int i = 1; i <= n; i++) {
            if (i & rightmostSetBit) {
                xorSet ^= i;
            } else {
                xorNotSet ^= i;
            }
        }

        for (int num : nums) {
            if (num & rightmostSetBit) {
                xorSet ^= num;
            } else {
                xorNotSet ^= num;
            }
        }

        
        for (int num : nums) {
            if (num == xorSet) {
                return {xorSet, xorNotSet};
            }
        }

        
        return {xorNotSet, xorSet};
    }
};

