#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp = nums;
        int ops1 =0 ;
        for(int i=0;i<n-1;i++){
            if(temp[i]==-1) {
                temp[i]=1;
                temp[i+1]*=-1;
                ops1++;
            }
        }
        bool allOne = true;
        for(int i=0;i<n;i++) {
            if(temp[i]==-1) allOne = false;
        }
        int ops2=0;
        temp = nums;

        for(int i=0;i<n-1;i++){
            if(temp[i]==1){
                temp[i]=-1;
                temp[i+1]*=-1;
                ops2++;
            }
        }
        bool allMinusOne = true;
        for(int i=0;i<n;i++) {
            if(temp[i]==1) allMinusOne = false;
        }
        int ops;
        if(allOne && allMinusOne){
            ops = min(ops1,ops2);
        }
        else if(allOne) ops = ops1;
        else if(allMinusOne) ops = ops2;
        else return false;
        return k>=ops; 
    }
};