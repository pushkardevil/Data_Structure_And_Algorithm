class Solution {
public:
    int solve( TreeNode* root , int &maxi){
        if(root == NULL) return 0;

        int lm=max(0,solve(root->left,maxi));
        int rm=max(0, solve(root->right , maxi));
        maxi=max(maxi,lm+rm+root->val);

        return root->val+max(lm,rm);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root , maxi);
        return maxi;
    }
};
