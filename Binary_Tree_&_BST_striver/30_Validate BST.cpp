class Solution {
public:
    bool isbst(TreeNode* root , long min , long max){
        //base case
        if( root == NULL){
            return true;
        }
        
        if(root->val > min && root->val < max){
            bool left=isbst(root->left , min , root->val);
            bool right=isbst( root->right , root->val , max);
            
            if( left && right){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        return isbst( root , LONG_MIN , LONG_MAX);
    }
};
