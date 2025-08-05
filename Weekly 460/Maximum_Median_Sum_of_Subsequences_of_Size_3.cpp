#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int st = 0;
        int en = n-2;
        long long ans = 0;
        while(st<en){
            ans += nums[en];
            en-=2;
            st++;
        }
        return ans;
    }
};