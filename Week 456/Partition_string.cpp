#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    vector<string> partitionString(string s) {
        int n = s.size();
        unordered_map<string,bool> mp;
        string st = "";
        vector<string> ans;
        for(int i = 0;i<n;i++){
            st += s[i];
            if(mp.find(st)==mp.end()){
                ans.push_back(st);
                mp[st] = true;
                st= "";
            }
        }
        return ans;
    }
};