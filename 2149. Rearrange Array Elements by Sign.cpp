//Approach 1 
//remember here i/2 in second loop otherwise smaller vector arrays ke liye out of  bound chala jaega 
//space complexity  O(N) ,time complexity O(N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>a;
        vector<int>b;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            a.push_back(nums[i]);
            else
            b.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
           if(i%2==0){
               nums[i]=a[i/2];
           }
           else{
               nums[i]=b[i/2];
           }
        }
        return nums;
    }
};
//Approach 2
//Here you have used two iteration, can you do it in one iterations ?
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int pos=0,neg=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
            ans[pos]=nums[i];
            pos+=2;
        }
           else{
               ans[neg]=nums[i];
               neg+=2;
           }
        }
        return ans;
       
    }
};
//what if the order doesn't matter , can you do that in-place ?
/*As we know that order doesn't matter and also we have equal no. of positive and negatives.
So what if positive is not at the correct index, we can get negative and swap it. same for the negative if it is not at correct index , we can get positive and swap. */
// TC : O(N) SC: O(1)
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int pos = 0, neg = 1;
        while(pos < n && neg < n) {
            if(nums[pos] >= 0) pos += 2;
            else if(nums[neg] < 0) neg += 2;
            else {
                int temp = nums[pos];
                nums[pos] = nums[neg];
                nums[neg] = temp;
            }
        }
        return nums;
    }
};

