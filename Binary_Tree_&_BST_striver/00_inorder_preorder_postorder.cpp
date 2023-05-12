
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

///////////////////////////////////////////////    preorder(root-left-right)-iterative solution    ////////////////////////////////////////////////////////////////////////
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


///////////////////////////////////////////////    inorder(root-left-right)-iterative solution    ////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        if(root == NULL) return inorder;

        TreeNode* node=root;
        stack<TreeNode*>s;

        while(true){
            if(node != NULL){
                s.push(node);
                node=node->left;
            }
            else{
                if(s.empty()) break;
                node=s.top();
                s.pop();

                inorder.push_back(node->val);
                node=node->right;
            }
        }
        return inorder;
    }
};


///////////////////////////////////////////////    postorder(root-left-right)-iterative solution     ////////////////////////////////////////////////////////////////////////
