
///////////////////////////////////////////////    Inorder(left-root-right)    ////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void inorder(TreeNode* root ,vector<int>&v ){
        if( root == NULL){
            return;
        }
        
        inorder(root->left , v);
        v.push_back(root->val);
        inorder(root->right , v);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        inorder(root , v);
        return v;
    }
};

///////////////////////////////////////////////    preorder(root-left-right)    ////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void preorder(TreeNode* root , vector<int>&v){
        if(root == NULL) return;

        v.push_back(root->val);
        preorder(root->left , v);
        preorder(root->right , v);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(root , v);
        return v;
    }
};

///////////////////////////////////////////////    postorder(left-right-root)    ////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void preorder(TreeNode* root , vector<int>&v){
        if(root == NULL) return;

        
        preorder(root->left , v);
        preorder(root->right , v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        preorder(root , v);
        return v;
    }
};
