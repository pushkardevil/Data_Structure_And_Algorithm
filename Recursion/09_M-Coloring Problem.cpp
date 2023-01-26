// LINK :https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1#

class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool ispossible(int node , int color[] , bool graph[101][101] , int n , int col){
        for(int k=0;k<n;k++){
            if(k != node && graph[k][node] ==1 && color[k] == col) return false;
            
        }
        return true;
    }
    bool solve(int node , int color[] , bool graph[101][101] , int m , int n){
        //base case 
        if(node == n) return true;
        
        for(int i=1;i<=m;i++){
            if(ispossible(node , color , graph , n , i)){
                color[node]=i;
                if( solve(node+1 , color , graph , m , n) == true) return true;
                color[node]=0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[n]={0};
        if(solve(0 , color , graph , m , n) == true) return true;
        return false;
    }
};
