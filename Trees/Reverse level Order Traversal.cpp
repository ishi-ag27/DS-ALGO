/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root)  return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if (it)
                temp.push_back(it->val);
            if (!it){
                ans.push_back(temp);
                temp.clear();
                if (!q.empty())
                    q.push(NULL);
            }
            else{
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
