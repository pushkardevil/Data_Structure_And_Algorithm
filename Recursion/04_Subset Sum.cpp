//LINK :https://practice.geeksforgeeks.org/problems/subset-sums2234/1

////////////////////////////////      optimal solution ///////////////////////////////////////////////////////////////////////////

class Solution
{
public:
void solve(int ind , vector<int>&ds , vector<int>arr , int n , vector<vector<int>>&res){
	//base case
	if(ind == n){
		res.push_back(ds);
		return;
	}
	
	//take or pick the particular index into the subsequence.
	ds.push_back(arr[ind]);
	solve(ind+1 , ds, arr , n , res);
	ds.pop_back();
	
	//not take condition
	solve(ind+1 , ds, arr , n , res);
}
    vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code h
        vector<vector<int>> res;
        vector<int>ds;
        int index=0;
        solve( 0 , ds , arr ,n, res);
        
        vector<int>ans;
        for(int i=0;i<res.size();i++){
            int sum=0;
            for(auto it:res[i]){
                sum+=it;
            }
            ans.push_back(sum);
        }
        
        return ans;
        
        
    }
};

////////////////////////////////      optimal solution ///////////////////////////////////////////////////////////////////////////

class Solution
{
public:
void solve(int ind , int sum , vector<int>&ans , vector<int>&arr , int n){
    //base case
    if(ind == n){
        ans.push_back(sum);
        return;
    }
    
    //pick the element
    solve(ind+1 , sum+arr[ind] ,ans , arr  , n);
    
    //dont pick the element
    solve(ind+1 , sum , ans ,arr  , n);
    
}

    vector<int> subsetSums(vector<int> arr, int n)
    {
        vector<int>ans;
        solve(0 , 0 ,ans , arr , n);
        sort(ans.begin() , ans.end());
        
        return ans;
        
    }
};
