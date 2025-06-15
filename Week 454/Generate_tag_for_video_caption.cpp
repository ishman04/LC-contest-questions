#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    string generateTag(string caption) {
        string result = "#";
        if(!caption.empty()){
            if(caption[0]>='A' && caption[0]<='Z'){
                char ch = (caption[0] - 'A') + 'a';
                result += ch;
            }
            else if(caption[0]>='a' && caption[0]<='z'){
                result += caption[0];
            }
        }
        for(int i=1;i<caption.length();){
            if(result.length() == 100) break;
            if(caption[i] == ' '){
                while(caption[i] == ' ') i++;
                if(caption[i]>='A' && caption[i]<='Z'){
                    char ch = caption[i];
                    result += ch;
                } 
                else if(caption[i]>='a' && caption[i]<='z'){
                    char ch = (caption[i]-'a') + 'A';
                    result += ch;
                }
                i++;
            }
            else if(caption[i]>='a' && caption[i]<='z'){
                result += caption[i];
                i++;
            }
            else if(caption[i]>='A' && caption[i]<='Z'){
                char ch = (caption[i]-'A') + 'a';
                result += ch;
                i++;
            }
            else i++;
        }
        return result;
    }
};