class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int ans=0;
        queue<pair<TreeNode* , int>>q;
        q.push({root , 0});

        while(!q.empty()){
            int size=q.size();
            int curIndex=q.front().second;
            int leftMost , rightMost;

            for(int i=0;i<size;i++){
                int curr_ind=q.front().second-curIndex;
                TreeNode* node=q.front().first;
                q.pop();

                if(i == 0) leftMost=curr_ind;
                if(i == size-1) rightMost=curr_ind;

                if(node->left) q.push({node->left , 2*curr_ind +1});
                if(node->right) q.push({node->right , 2*curr_ind +2});
            }
            ans=max(ans , rightMost-leftMost+1);
        }
        return ans;
    }
};
