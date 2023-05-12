class Solution {
public:
int solve(TreeNode* root , int &diameter){
    if(root == NULL) return 0;

    int leftHeight=solve(root->left , diameter);
    int rightHeight=solve(root->right , diameter);

    diameter=max(diameter, leftHeight+rightHeight);

    return 1+max(leftHeight , rightHeight);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
};
