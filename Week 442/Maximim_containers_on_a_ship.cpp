#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxContainers(int n, int w, int maxWeight) {
            int x = n*n*w;
            return min(x,maxWeight)/w;
            
        }
    };
int main(){

}