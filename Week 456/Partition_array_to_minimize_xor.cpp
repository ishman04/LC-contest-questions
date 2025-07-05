#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    int dp(int i, int k, vector<int>& nums, vector<vector<int>>& memo) {
        if (k == 0 && i == nums.size())
            return 0;
        if (k == 0 || i == nums.size())
            return INT_MAX;
        if (memo[i][k] != -1)
            return memo[i][k];

        int minAns = INT_MAX;
        int currXor = 0;
        for (int j = i; j < nums.size(); ++j) {
            currXor ^= nums[j];
            int next = dp(j + 1, k - 1, nums, memo);
            if (next != INT_MAX)
                minAns = min(minAns, max(currXor, next));
        }

        return memo[i][k] = minAns;
    }
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));
        return dp(0, k, nums, memo);
    }
};