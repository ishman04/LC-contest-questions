#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
public:
    using ll = long long;

    char processStr(string s, ll k) {
        ll length = 0;

        // Step 1: Calculate final length after all operations
        for (char c : s) {
            if (c == '*') {
                length = max(0LL, length - 1);
            } else if (c == '#') {
                length *= 2;
            } else if (c >= 'a' && c <= 'z') {
                length++;
            }
            // '%' has no effect on length
        }

        // If k is beyond final length, return '.'
        if (k >= length) return '.';

        // Step 2: Walk the string in reverse to trace back character at index k
        reverse(s.begin(), s.end());

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                length--;
                if (length == k) return c;
            } else if (c == '#') {
                // Undo duplication
                if (k >= length / 2) {
                    k -= length / 2;  // adjust index to first half
                }
                length /= 2;
            } else if (c == '*') {
                length++;
            } else if (c == '%') {
                k = length - 1 - k;  // reverse the index
            }
        }

        return '.';
    }
};
