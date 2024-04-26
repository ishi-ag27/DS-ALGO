class Solution {
public:
    pair<bool,int> isBalancedFast(TreeNode* root){
        if(root==NULL){
            pair<bool,int>p=make_pair(true,0);
            return p;
        }
        pair<bool,int>leftans=isBalancedFast(root->left);
        pair<bool,int>rightans=isBalancedFast(root->right);
        bool left=leftans.first;
        bool right=rightans.first;
        bool diff= abs(leftans.second-rightans.second)<=1;
        pair<bool,int>ans;
        if(left && right && diff){
            ans.first=true;
        }
        else{
            ans.first=false;
        }
        ans.second=max(leftans.second,rightans.second)+1;
        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first;
    }
};
