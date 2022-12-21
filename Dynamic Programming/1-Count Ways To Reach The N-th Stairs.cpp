#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.
    int prev2 = 1;
      int prev = 1;

      for(int i=2; i<=nStairs; i++){
          int cur_i = prev2+ prev;
          prev2 = prev;
          prev= cur_i;
      }
    return prev;
}
