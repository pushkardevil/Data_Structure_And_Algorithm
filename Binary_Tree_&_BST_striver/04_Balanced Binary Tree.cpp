class Solution {
public:
int solve(TreeNode* root ){
    if(root == NULL) return 0;

    int leftHeight=solve(root->left);
    if(leftHeight == -1) return -1;

    int rightHeight=solve(root->right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight-rightHeight) >1) return -1;

    return 1+max(leftHeight , rightHeight);


}
    bool isBalanced(TreeNode* root) {
        if(solve(root) == -1) return false;
        else return true;

    }
};
