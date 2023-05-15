
class Solution {
public:
int leftHeight(TreeNode* root){
    int height=0;
    while(root != NULL){
        height++;
        root=root->left;
    }
    return height;
}
int rightHeight(TreeNode* root){
    int height=0;
    while(root != NULL){
        height++;
        root=root->right;
    }
    return height;
}
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh=leftHeight(root);
        int rh=rightHeight(root);

        if(lh == rh) return pow(2,lh)-1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
