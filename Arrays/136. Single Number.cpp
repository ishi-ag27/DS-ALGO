/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]
Output: 1
Example 2:

Input: nums = [4,1,2,1,2]
Output: 4
Example 3:

Input: nums = [1]
Output: 1
 

Constraints:

1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/

//Approach 1
//TC O(N^2)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            int cnt=0;
            for(int j=0;j<n;j++){
                if(num==nums[j]){
                    cnt++;
                }
            }
            if(cnt==1) return num;
        }
        return -1;
    }
};

//Approach 2
//TC O(3N)   Hashing but it will fail for negatives and bigger numbers
//SC O(maxEl +1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        vector<int>hash(maxi+1,0);
        for(int i=0;i<n;i++){
            hash[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            if(hash[nums[i]]==1)
            return nums[i];
        }
    return -1;
    }
};

//Approach 3 
//TC O(NlogM)+ O(N/2+1)
//SC: O(N/2+1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
      
        for(auto it:mpp){
            if(it.second==1){
                return it.first;
            }
        }
        
    return -1;
    }
};

//Approach 4 
//TC O(N)
//SC O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int XOR=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            XOR=XOR^nums[i];
        }
        return XOR;
    }
};
