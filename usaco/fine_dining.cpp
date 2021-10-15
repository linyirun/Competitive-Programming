// http://www.usaco.org/index.php?page=viewproblem2&cpid=861
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
const int INF = 1000000000;

//const int MOD = 1000000007;
//const int MAX = 101;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("dining.in", "r", stdin);
    freopen("dining.out", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<pii>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges[u].push_back({v, cost});
        edges[v].push_back({u, cost});
    }
    
    // find shortest path to node n
    vector<int> dist_to_n(n + 1, INF), haybale_dist(n + 1, INF);
    dist_to_n[n] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, n});
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        
        int curr_cost = p.first, node = p.second;
        for (pii edge : edges[node]) {
            int dest = edge.first, edge_cost = edge.second;
            if (dist_to_n[dest] > curr_cost + edge_cost) {
                dist_to_n[dest] = curr_cost + edge_cost;
                q.push({dist_to_n[dest], dest});
            }
        }
    }
    
    for (int i = 0; i < k; i++) {
        int idx, val;
        cin >> idx >> val;
        haybale_dist[idx] = dist_to_n[idx] - val;
        q.push({haybale_dist[idx], idx});
    }
    
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        
        int curr_cost = p.first, node = p.second;
        for (pii edge : edges[node]) {
            int dest = edge.first, edge_cost = edge.second;
            if (haybale_dist[dest] > curr_cost + edge_cost) {
                haybale_dist[dest] = curr_cost + edge_cost;
                q.push({haybale_dist[dest], dest});
            }
        }
    }
    
    for (int i = 1; i < n; i++) {
        if (dist_to_n[i] >= haybale_dist[i]) cout << "1\n";
        else cout << "0\n";
    }
    
}
