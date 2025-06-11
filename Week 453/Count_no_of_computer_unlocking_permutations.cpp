#include<bits/stdc++.h>
using namespace std;
int main(){

}
const long long mod = 1e9 +7;
class Solution {
public:
    int countPermutations(vector<int>& arr) {
        int n = arr.size();
        int root = arr[0];
        int mini = arr[0];
        for (int i=1;i<n;i++){
            if(mini>=arr[i]) return 0;
        }
        int ans = 1;
        for(int i=1;i<n;i++){
            ans = ((long long)ans*i)%mod;
        }
        return ans;
    }
};