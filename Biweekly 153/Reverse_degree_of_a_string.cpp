#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
    public:
        int reverseDegree(string s) {
            int n = s.length();
            int ans=0;
            for(int i=0;i<n;i++){
                char ch = s[i];
                int num = 26-((int)ch-97);
                ans += (i+1)*num;
                
            }
            return ans;
        }
    };