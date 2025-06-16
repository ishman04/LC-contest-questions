#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<int> dp;
    string word_1;
    string word_2;
    int n;
    
    int ans(string s1, string s2){
        int cnt = 0;
        int n1 = s1.size();
        for(int i=0;i<n1;i++){
            if(s1[i]==s2[i]) continue;
            for(int j=i+1; j<n1;j++){
                if(s1[i] == s2[j] && s1[j] == s2[i]){
                    swap(s1[i],s1[j]);
                    cnt++;
                    break;
                }
            }
            if(s1[i]!=s2[i]){
                s1[i]=s2[i];
                cnt++;
            }
        }
        return cnt;
    }
    int f(int i){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int res = INT_MAX;
        for(int j=i+1;j<=n;j++){
            string tmp1 = word_1.substr(i,j-i);
            string tmp2 = word_2.substr(i,j-i);

            res = min(res,f(j) + ans(tmp1,tmp2));

            reverse(tmp1.begin(),tmp1.end());
            res = min(res, f(j)+1+ans(tmp1,tmp2));
        }
        return dp[i] = res;
    }
    int minOperations(string word1, string word2) {
       dp.resize(105,-1);
       word_1 = word1;
        word_2 = word2;
        n= word_1.size();
       return f(0);
        
    }
};