#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        int moves = 0;
        bool swp = false;
        while(sy<ty || sx<tx){
            if(tx > ty){
                swap(tx,ty);
                swap(sx,sy);
            }
            if(swp && min(sx,sy) == min(tx,ty) && max(sx,sy) == max(tx,ty)) break;
            if(ty>2*tx){
                if(ty%2) break;
                ty /= 2;
                moves++;
            }
            else if(ty >= tx){
                if(tx == ty) swp = true;
                ty -= tx;
                moves++;
            }
        }
        if(tx==sx && ty==sy) return moves;
        if(swp && min(sx,sy) == min(tx,ty) && max(sx,sy) == max(tx,ty)) return moves;
        return -1;
    }
};