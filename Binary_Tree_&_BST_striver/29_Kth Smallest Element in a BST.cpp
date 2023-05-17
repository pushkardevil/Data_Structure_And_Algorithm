

class Solution {
public:
void solve(TreeNode* root , int &cnt , int k ,int &ans){
    if(root == NULL) return;

    solve(root->left , cnt , k , ans );
    cnt++;
    if(cnt == k){
        ans=root->val;
        return;
    }
    solve(root->right , cnt , k , ans);
}
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;

        int cnt=0;
        int ans;
        solve(root , cnt , k , ans);   
        return ans;
     }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
void solve(TreeNode* root , vector<int>&v){
    if(root == NULL) return;

    solve(root->left , v);
    v.push_back(root->val);
    solve(root->right , v);
}
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return -1;

        vector<int>v;
        solve(root , v);
        return v[k-1];
    }
};
