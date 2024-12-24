#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define endl "\n"
 
signed main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int n; cin >> n;
 
    vector<vector<int>> adj(n + 1);
 
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    

    // For every node find the two largest path from itself and to some leaf of its subtree and then add them to get the diameter.
 
    auto dfs = [&](int node, int parent, int &diameter, auto&& self) -> int {
        int mx1 = 0, mx2 = 0;
        for(auto child : adj[node]) {
            if(parent == child) continue;
            int depth = self(child, node, diameter, self);
            if(depth > mx1) {
                mx2 = mx1;
                mx1 = depth;
            } else if(depth > mx2){
                mx2 = depth;
            }
        }
        diameter = max(diameter, mx1 + mx2);
        return mx1 + 1;
    };

    int diameter = 0;
    dfs(1, 0, diameter, dfs); 

    cout << diameter << endl;
} 
