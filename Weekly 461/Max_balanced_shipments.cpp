#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        if (n == 1)
            return 0;
        int left = 0;
        int right = 1;
        int ans = 0;
        int currMax = weight[left];
        while (right < n) {
            if (weight[right] < currMax) {
                ans++;
                left = right + 1;
                right = right + 2;
                if (left < n) {
                    currMax = weight[left];
                }
            } else {
                currMax = weight[right];
                right++;
            }
        }
        return ans;
    }
};