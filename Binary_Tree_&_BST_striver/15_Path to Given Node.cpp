bool path(TreeNode* root, int B , vector<int>&ans){
     if(root == NULL) return false;
     
     ans.push_back(root->val);
     if(root->val == B) return true;
     
     if(path(root->left , B , ans ) || path(root->right , B , ans )) return true;
     
     ans.pop_back();
     return false;
 }
vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int>ans;
    if(root == NULL) return ans;
    
    path(root , B , ans);
    return ans;
}
