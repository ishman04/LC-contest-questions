#include<bits/stdc++.h>
using namespace std;
int main(){

}
class Solution {
    public:
        int intersect(vector<int>& a,vector<int>& b){
            int count = 0;
                unordered_set<int> elements(a.begin(),a.end());
                for (int num : b) {
                if (elements.count(num)) {
                    count++;
                    elements.erase(num);
                }
            }
            return count;
        }
        vector<bool> visited;
        void dfs(int src,vector<vector<int>>& v){
            if(visited[src]) return;
            visited[src] = true;
            for(int i = 0;i<v[src].size();i++){
                dfs(v[src][i],v);
            }
        }
        int numberOfComponents(vector<vector<int>>& properties, int k) {
            int n = properties.size();
            vector<vector<int>> v(n);
            int val;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    val = intersect(properties[i],properties[j]);
                    if(val>=k){
                        v[i].push_back(j);
                        v[j].push_back(i);
                    }
                }
            }
            visited.resize(n,false);
            int ans = 0;
            for(int i = 0;i<n;i++){
                if(visited[i]) continue;
                ans++;
                dfs(i,v);
            }
            return ans;
        }
    };