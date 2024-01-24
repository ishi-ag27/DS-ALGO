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
int freq[10]={0};
bool isPseudoPalindrome()
{
    int cnt=0;
    for(int i=0;i<10;i++) {
        cnt+=(freq[i]%2); if(cnt==2) return false;
    }
    
    return true;
 
}
    int pseudoPalindromicPaths (TreeNode* root) {
       if(root==NULL)
       return 0;
       freq[root->val]++;
       if(root->left==NULL and root->right==NULL and isPseudoPalindrome())
       {  freq[root->val]--; return 1;}

        int left=pseudoPalindromicPaths(root->left);
        int right=pseudoPalindromicPaths(root->right);
        freq[root->val]--;
        return left+right;
    }
};
