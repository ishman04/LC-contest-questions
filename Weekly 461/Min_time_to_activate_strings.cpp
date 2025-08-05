#include<bits/stdc++.h>
using namespace std;
int main(){

}

class Solution {
public:
    using ll = long long;
    int minTime(string s, vector<int>& order, ll k) {
        int n = order.size();
        ll cnt = 0; //number of valid substr activated
        set<int> st = {-1,n}; //-1 before start of string and n beyond end of string. it keeps track of all positions that have already been turned into '*'
        for(int i=0;i<n;i++){
            int pos = order[i];
            auto it = st.lower_bound(pos); //return first idx in st that is not less than pos
            it--; //moves to prev index which is left boundary of segment that pos belongs to
            //*it gives left index of current non starred segment containing pos
            ll before = pos - int(*it); //calculates positions between left boundary and pos
            it = st.upper_bound(pos); //gets right boundary of current segment that pos belongs
            ll after = int(*it) - pos;
            cnt += before*after; //number of new valid substrings activated due to making pos a *
            if(cnt>=k) return i;
            st.insert(pos);
        }
        return -1;
    }
};