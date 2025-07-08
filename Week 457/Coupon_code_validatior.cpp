#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    static bool cmp(vector<string> &a,vector<string> &b){
         return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<vector<string>> v(n,vector<string>(2,"@"));
        unordered_set<string> allowed = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(int i = 0;i<n;i++){
            if(allowed.count(businessLine[i]) && isActive[i]){
                    bool flag = !code[i].empty();
                    for(int j=0;j<code[i].length();j++){
                        if(!flag) break;
                        if(!isalnum(code[i][j]) && code[i][j] !='_'){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        v[i][0] = businessLine[i];
                        v[i][1] = code[i];
                    }
                
            }
        }
        sort(v.begin(),v.end(),cmp);
        vector<string> ans;
        for(int i=0;i<v.size();i++){
            if(v[i][0] =="@")continue;
            ans.push_back(v[i][1]);
        }
        return ans;
    }
};