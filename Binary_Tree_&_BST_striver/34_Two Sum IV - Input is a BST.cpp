class Solution {
public:
    void inorder( TreeNode* root , vector<int>&v){
	//base case
	if(root == NULL){
		return;
	}
	
	
	inorder(root->left , v);
	v.push_back(root->val);
	inorder(root->right , v);	
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>v;
        inorder(root , v);
        
        int n=v.size();
        int s=0;
        int e=n-1;
        
        while( s < e){
            if( v[s] +v[e] == k){
                return true;
            }
            else if( v[s] + v[e] > k){
                e--;
            }else{
                s++;
            }
        }
        return false;
    }
};
