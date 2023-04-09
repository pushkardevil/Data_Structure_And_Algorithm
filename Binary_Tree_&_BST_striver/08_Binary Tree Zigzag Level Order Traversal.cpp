class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL) return ans;
        
        int cnt=0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int>v;

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                v.push_back(node->val);
                q.pop();

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            if(cnt%2 ==1){
                reverse(v.begin(),v.end());
            }
            ans.push_back(v);
            cnt++;
        }
        return ans;

    }
};
