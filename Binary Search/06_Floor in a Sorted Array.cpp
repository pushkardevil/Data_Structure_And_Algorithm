#include <bits/stdc++.h> 

int floorSearch(vector<int> & v, int x, int n)
{
    // Write your code here.
    int s=0;
    int e=n-1;
    int res=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid] == x){
            return v[mid];
        }
        else if(v[mid]>x){
            e=mid-1;
        }
        else{
            res=mid;
            s=mid+1;
        }
    }
    if(res==-1) return -1;
    return v[res];
}
