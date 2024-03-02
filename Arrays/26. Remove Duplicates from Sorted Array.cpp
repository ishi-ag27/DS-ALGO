//Approach 1 : Time Complexity : O(NlogN+N) , Space Complexity O(N)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int index=0;
        for(auto it:s){
            nums[index]=it;
            index++;
        }
        return index;
    }
};
//Approach 2: TC : O(N) , SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j;
        for(j=1;j<nums.size();j++){
          
                if(nums[j]!=nums[i]){
                    nums[i+1]=nums[j];
                    i++;
                }
            
        }
        return i+1;
    }
};
