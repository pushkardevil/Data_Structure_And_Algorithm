///////////////////////////////////////// CODE SAME HAI CEIL KI TREH BSS THORI SI DIFFERENCE HAI     ///////////////////////////////////////////
//// leetcode-Find Smallest Letter Greater Than Target

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int s=0;
        int e=n-1;
        char res=letters[0];
        while(s<=e){
            int mid=s+(e-s)/2;
            if(int(letters[mid]) == target) s=mid+1;
            else if(int(letters[mid]) < target) s=mid+1;
            else if(int(letters[mid]) > target){
                res=letters[mid];
                e=mid-1;
            }
        }
        return res;
    }
};
