#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
    public:
        int maxActiveSectionsAfterTrade(string s) {
            int n = s.length();
            int initial1 = 0;
            for(int i=0;i<n;i++){
                if(s[i]=='1') initial1++;
            }
            if(n==initial1) return initial1;
            vector<int> zeros;
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    int count=1;
                    for(int j=i+1;j<n;j++){
                    if(s[j]==s[i]){
                        count++;
                        i=j;
                    }
                    else{
                        i=j;
                        break;
                    }
                    
                }
                    zeros.push_back(count);
                }
                
            }
            int mx = INT_MIN;
            if(zeros.size()==1) return initial1;
            for(int i=1;i<zeros.size();i++){
                int sum = zeros[i-1]+zeros[i];
                mx = max(mx,sum);
            }
            return mx + initial1;
        }
    };