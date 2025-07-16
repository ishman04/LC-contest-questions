#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    bool isPrime(int val){
        if(val <= 1) return false;
        if(val==2) return true;
        if(val%2==0) return false;
        for(int i = 3;i<val;i++){
            if(val%i==0) return false;
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto i: mp){
            if(isPrime(i.second)){
                return true;
            }
        }
        return false;
    }
};