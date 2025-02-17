/*
Given an array arr of distinct elements, the task is to return an array of all elements except the two greatest elements in sorted order.

Examples:

Input: arr[] = [2, 8, 7, 1, 5]
Output: [1, 2, 5] 
Explanation: Here we return an array contains 1 , 2, 5 and we leave two greatest elements 7 & 8. 
Input: arr[] = [7, -2, 3, 4, 9, -1]
Output: [-2, -1, 3, 4]
Explanation: Here we return an array contains -2 , -1, 3, 4 and we leave two greatest elements 7 & 9. 
Expected Time Complexity: O(nlog(n))
Expected Space Complexity: O(n)

Constraints:
3 ≤ arr.size ≤ 105
-106 ≤ arr[i] ≤ 106

*/
class Solution {
  public:
    vector<int> findElements(vector<int> arr) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(n<=2){
            return {};
        }
        vector<int>ans;
        for(int i=0;i<n-2;i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};

/*
Summary of Fixes
Vector Initialization	❌ vector<int> ans(n); (extra memory)	✅ Uses push_back() dynamically
Edge Case Handling	❌ Can break for small arrays	✅ Returns empty vector if needed
*/


