//LINK : https://leetcode.com/problems/subsets-ii/submissions/884267036/

class Solution {
public:
void solve(int index , vector<int>&v , vector<int>&nums , vector<vector<int>>&res){
    res.push_back(v);

    for(int i=index;i<nums.size();i++){
        if( index != i && nums[i] == nums[i-1]) continue;

        v.push_back(nums[i]);
        solve(i+1 , v , nums , res);
        v.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>>res;
        vector<int>v;

        solve(0 , v , nums , res);
        return res;

    }
};
