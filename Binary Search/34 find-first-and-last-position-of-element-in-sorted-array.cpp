class Solution {
public:
    int firstOccurence(vector<int>& nums, int target,int s,int e){
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
        if(target==nums[mid]){
            ans=mid;
            e=mid-1;
        }
        else if(target>nums[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
        }
        return ans;
    }
    int lastOccurence(vector<int>& arr, int target,int s,int e){
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
        if(target==arr[mid]){
            ans=mid;
            s=mid+1;
        }
        else if(target>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
         mid=s+(e-s)/2;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        vector<int>v;
        int first=firstOccurence(nums,target,s,e);
        int second=lastOccurence(nums,target,s,e);
        v.push_back(first);
        v.push_back(second);
        return v;
    }
};
