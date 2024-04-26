class Solution {
    int help(TreeNode* root, int& diameter) {
        if (root == NULL) return 0;                         // Base case: NULL node has height 0
        int left = help(root->left, diameter);             // Height of left subtree
        int right = help(root->right, diameter);          // Height of right subtree
        diameter = max(diameter, left + right);          // Update diameter
        return max(left, right) + 1;                    // Return current subtree height
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;                            // Initialize diameter to 0
        help(root, diameter);                       // Call helper function
        return diameter;                           // Return final diameter
    }
};

//Approach 2:
class Solution {
public:
    pair<int,int> diameterFast(TreeNode* root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int>left=diameterFast(root->left);
        pair<int,int>right=diameterFast(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};


