// http://www.usaco.org/index.php?page=viewproblem2&cpid=789
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;

struct DSU {
    vector<int> par, sz;
    
    DSU(int n) {
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            sz[i] = 1;
            par[i] = i;
        }
    }
    
    int find_par(int x) {
        if (par[x] == x) return x;
        else return par[x] = find_par(par[x]);
    }
    
    void merge(int a, int b) {
        a = find_par(a);
        b = find_par(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b];
        par[b] = a;
    }
};
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    
    int n, q;
    cin >> n >> q;
    
    vector<pair<int, pii>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edges[i] = {cost, {u, v}};
    }
    
    // {cost, {node idx, query idx}}
    vector<pair<int, pii>> queries(q);
    vector<int> ans(q);
    
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        queries[i] = {k, {v, i}};
    }
    
    sort(queries.begin(), queries.end(), greater<pair<int, pii>>());
    sort(edges.begin(), edges.end(), greater<pair<int, pii>>());
    
    DSU dsu(n);
    int ptr = 0;
    for (auto p : queries) {
        int k = p.first, v = p.second.first, idx = p.second.second;
        
        while (ptr < n - 1 && edges[ptr].first >= k) {
            dsu.merge(edges[ptr].second.first, edges[ptr].second.second);
            ptr++;
        }
        
        ans[idx] = dsu.sz[dsu.find_par(v)];
    }
    
    for (int i = 0; i < q; i++) cout << ans[i] - 1 << '\n';
    
}
