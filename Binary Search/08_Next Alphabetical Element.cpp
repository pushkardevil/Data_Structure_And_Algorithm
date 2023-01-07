///////////////////////////////////////// CODE SAME HAI CEIL KI TREH BSS THORI SI DIFFERENCE HAI     ///////////////////////////////////////////
#include <bits/stdc++.h> 
int ceilingInSortedArray(int n, int x, vector<int> &arr){
    // Write your code here.
    int s=0;
    int e=n-1;
    char res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid] == x){
            s=mid+1;
        }
        else if(arr[mid] > x){
            res=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    if(res ==-1) return -1;
    return arr[res];
}
