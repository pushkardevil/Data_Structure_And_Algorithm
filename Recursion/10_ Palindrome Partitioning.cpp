// LINK : https://leetcode.com/problems/palindrome-partitioning/description/

class Solution {
public:
bool isPalindrome(string s,int start,int end ){
         while(start<end){
             if(s[start++] != s[end--]){return false;}
         }
         return true;
     }
void solve(int indx , string s , vector<string>&v , vector<vector<string>>&ans){
    //base case
    if(indx == s.size()){
        ans.push_back(v);
        return;
    }

    for(int i=indx;i<s.size();i++){
        if(isPalindrome(s , indx , i)){
            v.push_back(s.substr(indx , i-indx+1));
            solve(i+1 , s , v , ans);
            v.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>v;
        solve(0 , s , v , ans);
        return ans;
    }
};
