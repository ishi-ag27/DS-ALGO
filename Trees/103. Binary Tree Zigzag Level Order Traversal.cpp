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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        bool leftToRight=true;
        while(!q.empty()){
            int size=q.size();
            vector<int>ans(size);
            for(int i=0;i<size;i++){
            TreeNode* frontNode=q.front();
            q.pop();
            int index=leftToRight?i:size-i-1;
            ans[index]=frontNode->val;
            if(frontNode->left){
                q.push(frontNode->left);

            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
            }
            //direction change
            leftToRight=!leftToRight;
            res.push_back(ans);

            
        }
        return res;
    }
};

//Approach 2
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        return ans;
        queue<TreeNode*> q;
        q.push(root);
        int c=1;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> arr(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                arr[i]=temp->val;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
            }
            if(c%2==0)
            reverse(arr.begin(),arr.end());
            ans.push_back(arr);
            c++;
        }
        return ans;
    }
};
