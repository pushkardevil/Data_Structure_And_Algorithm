class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base case
        if( p == NULL && q==NULL) return true;
        if( p == NULL && q!=NULL) return false;
        if( p != NULL && q==NULL) return false;

        
        
        bool left=isSameTree(p->left , q->right);
        bool right=isSameTree(p->right , q->left);
        bool value= p->val == q->val;
        
        if( left  && right && value) return true;
        else return false;
        
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* l=root;
        TreeNode* r=root;      
        return isSameTree( l , r);
        
    }
};
