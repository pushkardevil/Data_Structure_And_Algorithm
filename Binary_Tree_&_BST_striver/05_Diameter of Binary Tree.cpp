class Solution {
public:
    int solve( TreeNode* root , int &diameter){
        if(root == NULL) return 0;

        int lh=solve(root->left,diameter);
        int rh=solve(root->right,diameter);

        diameter=max(diameter,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
};
