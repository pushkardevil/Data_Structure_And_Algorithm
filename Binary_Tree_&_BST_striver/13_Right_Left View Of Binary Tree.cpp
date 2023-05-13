/////////////////////////////////////// Right View //////////////////////////////////////////////////////////////////


class Solution {
public:
void solve(TreeNode* root , int level , vector<int>&ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->val);
    solve(root->right , level+1 , ans);
    solve(root->left , level+1 , ans);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;

        solve(root , 0  , ans);
        return ans;
    }
};

/////////////////////////////////////// Left View //////////////////////////////////////////////////////////////////

class Solution {
public:
void solve(TreeNode* root , int level , vector<int>&ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->val);
    solve(root->left , level+1 , ans);
    solve(root->right , level+1 , ans);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;

        solve(root , 0  , ans);
        return ans;
    }
};
