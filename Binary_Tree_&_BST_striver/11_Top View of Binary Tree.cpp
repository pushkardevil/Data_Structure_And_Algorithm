class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int>top;
        if(root == NULL) return top;
    
        
        queue<pair<Node * , int>>q;   //{node , line}
        map<int , int>mp;         // {line , node->val}
    
        q.push({root, 0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            Node * node=p.first;
            int line=p.second;
    
            if(mp.find(line) == mp.end()) mp[line]=node->data;
    
            if(node->left ) q.push({node->left , line-1});
            if(node->right ) q.push({node->right , line+1});
        }
    
        for(auto it:mp){
            top.push_back(it.second);
        }
        return top;
    }

};
