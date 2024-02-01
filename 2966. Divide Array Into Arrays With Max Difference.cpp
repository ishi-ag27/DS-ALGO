class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int i,n;
        sort(nums.begin(),nums.end());
        n=nums.size();
        vector<vector<int>>re(n/3);
        for(i=0;i<n/3;i++)
        {
            if(nums[3*i+2]-nums[3*i]>k)
            return {};
            re[i]={nums[3*i],nums[3*i+1],nums[3*i+2]};
        }
        return re;
    }
};
