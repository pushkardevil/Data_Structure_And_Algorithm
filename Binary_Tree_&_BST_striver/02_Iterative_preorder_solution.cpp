class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL) return ans;

        stack<TreeNode*>s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();

            ans.push_back(node->val);
            if(node->right != NULL) s.push(node->right);
            if(node->left != NULL) s.push(node->left);
        }
        return ans;
    }
};
