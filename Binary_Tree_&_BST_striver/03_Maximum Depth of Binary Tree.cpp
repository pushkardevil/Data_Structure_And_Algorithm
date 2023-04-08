///////////////////////////////////////////////////////  BY LEVEL ORDER TRAVERSAL  ///////////////////////////////////////////////////////////////////////

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int cnt=0;
        if(root == NULL) return cnt;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            cnt++;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            
        }
        return cnt;
    }
};


////////////////////////////////////////////////////////////////////  RECURSION  /////////////////////////////////////////////////

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);

        return 1+max(leftHeight , rightHeight);
    }
};
