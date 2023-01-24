//LINK :https://leetcode.com/problems/combination-sum-ii/description/

class Solution {
public:
void solve(int ind ,int target , vector<int>&v , vector<int>&nums ,vector<vector<int>>&ans){
    //base case
    if(target == 0){
        ans.push_back(v);
        return;
    }

    for(int i=ind;i<nums.size();i++){
        if(i>ind && nums[i] == nums[i-1]) continue;
        if(target < nums[i]) break;

        v.push_back(nums[i]);
        solve(i+1 , target-nums[i] , v , nums , ans);
        v.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(0 , target , v , nums , ans);
        return ans;
    }
};
