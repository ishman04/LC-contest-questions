#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<vector<vector<long long>>> dp;
    long long dfs(int m, int n, vector<vector<int>>& waitCost, int time,int col,int row){
        if(col>=n || col<0 || row>=m || row<0) return 100000000000;
        if(dp[time%2][row][col] != -1) return dp[time%2][row][col];
        if(row == m-1 && col ==n-1){
            return 0;
        }
        long long cost = 0;
        if(time % 2 == 0){
            cost = waitCost[row][col] + dfs(m,n,waitCost,time+1,col,row);
        }
        else{
            cost = min((row+2)*(col+1) + dfs(m,n,waitCost,time+1,col,row+1), (row+1)*(col+2) + dfs(m,n,waitCost,time+1,col+1,row));
        }
        return dp[time % 2][row][col] = cost;
    }
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        dp = vector<vector<vector<long long>>>(2, vector<vector<long long>>(m, vector<long long>(n, -1)));
        return 1+dfs(m,n,waitCost,1,0,0);
    }
};