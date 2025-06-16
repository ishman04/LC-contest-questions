#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
            mp[nums[i]].push_back(i);
        }
        long long count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int target = nums[i] * 2;
            if (st.find(target) == st.end())
                continue;
            auto it = lower_bound(mp[target].begin(), mp[target].end(), i);
            int before = int(it - mp[target].begin());
            int after = mp[target].size() - before;
            if (target == nums[i])
                after--;

            count += (long long)before * after;
            count %= int(1e9) + 7;
        }
        return (int)count;
    }
};