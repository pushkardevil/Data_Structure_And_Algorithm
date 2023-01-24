//Link : https://leetcode.com/problems/permutations/description/

class Solution {
public:
void solve(vector<int>&v , vector<int>&nums , vector<vector<int>>&res , vector<int>&vis){
    //base case
    if(v.size() == nums.size()){
        res.push_back(v);
    }


    for(int i=0;i<nums.size();i++){
        if(vis[i] == 0){
            v.push_back(nums[i]);
            vis[i]=1;
            solve(v , nums , res , vis);
            vis[i]=0;
            v.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        vector<int>v;
        vector<int>vis(n , 0);

        solve(v , nums ,res , vis);
        return res;
    }
};
