class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            root=val < root->val?root->left:root->right;
        }
        return root;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp=root;
        while( temp != NULL){
            if( temp->val == val){
                return temp;
            }
            else if( temp->val > val){
                temp=temp->left;
            }
            else{
                temp=temp->right;
            }
        }
        return NULL;
    }
};
