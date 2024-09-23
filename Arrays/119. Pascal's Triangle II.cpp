/*
  Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]
 

Constraints:

0 <= rowIndex <= 33
 

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
  */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans=1;
        vector<int>ansRow;
        ansRow.push_back(1);
        for(int i=1;i<rowIndex+1;i++){
            ans=ans*(rowIndex+1-i);
            ans=ans/i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
};
