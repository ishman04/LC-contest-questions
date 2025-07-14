#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        string res = "";
        for(int i=0;i<n;i++){
            string str1 = res;
            if(s[i]>='a' && s[i]<='z'){
                res += s[i];
            }
            else if(s[i]=='*'){
                if(res.length()>=1){
                    res.pop_back();
                }
            }
            else if(s[i]=='#'){
                
                res+=str1;
            }
            else if(s[i] == '%'){
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};