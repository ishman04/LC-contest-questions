#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool inc1 = false;
        bool dec = false;
        bool inc2 = false;
        int n = nums.size();
        int i=1;
        while(i<n && nums[i-1]<nums[i]) {i++; inc1=true;}
        while(i<n && nums[i-1]>nums[i]) {i++; dec=true;}
        if(i==n) return false;
        while(i<n && nums[i-1]<nums[i]) {i++; inc2=true;}
        
        return i==n ? inc1 && dec && inc2 : false;
    }
};