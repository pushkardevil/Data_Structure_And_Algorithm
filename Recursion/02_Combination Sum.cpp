// LINK: https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
void solve(int i ,int target , vector<int>v , vector<int>& candidates , vector<vector<int>>&res){
    //base case
    if(i == candidates.size()){
        if(target ==  0){
            res.push_back(v);
        }
        return;
    }


    //pick up the element.
    if(candidates[i] <= target){
        v.push_back(candidates[i]);
        solve(i , target - candidates[i] , v , candidates , res);
        v.pop_back();
    }


    solve(i+1 , target , v , candidates , res);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>v;

        solve(0 ,target , v , candidates , res);
        return res;
    }
};
