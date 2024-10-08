/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
 

Follow-up: Could you solve the problem in linear time and in O(1) space?
  */

//Brute Force Approach 
//TC : O(N^2)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int n=nums.size();
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i;j<n;j++){
            if(nums[j]==nums[i]){
                cnt++;
            }
        }
        if(cnt>n/2){
            return nums[i];
        }
    }
    return -1;
    }
};
