//Approach 1 : Hashing
//TC: O(nlogn) SC:O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            if(mpp.find(rem)!=mpp.end()){
                ans.push_back(i);
                 ans.push_back(mpp[rem]);
            }
            mpp[nums[i]]=i;
            
        }
        return ans;
    }
};

//Approach 2 : Two Pointers 
// TC: O(N)  SC:O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                ans.push_back(left);
                ans.push_back(right);
                break;
            }
            else if(numbers[left]+numbers[right]<target){
                left++;
            }
            else{
                right--;
            }
        }
    return ans;
     
    }
};
