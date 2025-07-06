#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    string convert(long long n, int base){
        string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string ans = "";
        while(n>0){
            int num = n%base;
            ans = chars[num] + ans;
            n=n/base;
        }
        return ans;
    }
    string concatHex36(int n) {
        long long num = n*n;
        long long num1 = n*n*n;
        string str1 = convert(num,16);
        string str2 = convert(num1,36);
        return str1+str2;
    }
};