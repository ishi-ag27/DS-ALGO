class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i,j;
        int n,m;
        n=nums.size();
        sort(nums.begin(),nums.end());
        m=n/2;
        return nums[m];
    }
