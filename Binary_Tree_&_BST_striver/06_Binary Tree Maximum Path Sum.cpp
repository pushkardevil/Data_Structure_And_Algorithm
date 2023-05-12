class Solution {
public:
int solve(TreeNode* root , int &sum){
    if(root == NULL) return 0;

    int lh=solve(root->left , sum);
    if(lh <0) lh=0;
    int rh=solve(root->right , sum);
    if(rh <0) rh=0;
    
    sum=max(sum , root->val+lh+rh);

    return root->val + max(lh,rh);
}
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        if(root == NULL) return sum;

        solve(root , sum);
        return sum;

    }
};
