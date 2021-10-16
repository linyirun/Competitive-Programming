// http://www.usaco.org/index.php?page=viewproblem2&cpid=899
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
const ll INF = 100000000000000;

//const int MOD = 1000000007;
//const int MAX = 101;

vector<vector<int>> adj;
vector<ll> cnt;
ll dfs(int node, int par) {
    ll curr = cnt[node];
    
    for (int dest : adj[node]) {
        if (dest != par) curr += dfs(dest, node);
    }
    return cnt[node] = curr;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//    freopen("shortcut.in", "r", stdin);
//    freopen("shortcut.out", "w", stdout);
    
    int n, m, t;
    cin >> n >> m >> t;
    
    adj.resize(n);
    cnt.resize(n);
    // number of cows at each barn

    for (int i = 0; i < n; i++) {
        cin >> cnt[i];
    }
    
    vector<vector<pll>> edges(n);
    for (int i = 0; i < m; i++) {
        ll u, v, cost;
        cin >> u >> v >> cost;
        u--, v--;
        edges[u].push_back({v, cost});
        edges[v].push_back({u, cost});
    }
    
    for (vector<pll> &v : edges) sort(v.begin(), v.end());
    vector<ll> dist(n, INF);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    
    vector<int> par(n);
    
    q.push({0, 0});
    dist[0] = 0;
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int node = p.second;
        
        for (auto p : edges[node]) {
            ll cost = p.second, dest = p.first;
            if (dist[dest] > dist[node] + cost) {
                par[dest] = node;
                dist[dest] = dist[node] + cost;
                q.push({dist[dest], dest});
            } else if (dist[dest] == dist[node] + cost) {
                par[dest] = min(par[dest], node);
            }
        }
    }
    for (int i = 1; i < n; i++) {
        adj[i].push_back(par[i]);
        adj[par[i]].push_back(i);
    }
    
    dfs(0, -1);
    ll best = 0;
    for (int i = 0; i < n; i++) {
        best = max(best, (dist[i] - t) * cnt[i]);
    }
    
    cout << best << '\n';
    
}
