// http://www.usaco.org/index.php?page=viewproblem2&cpid=968
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000

const int MAX = 100001;
int comp[MAX + 1];

string s;

vector<vector<int>> adj;
int curr_comp = 1;
void dfs(int node, int par) {
    comp[node] = curr_comp;
    for (int child : adj[node]) {
        if (child == par || s[child] != s[node]) continue;
        dfs(child, node);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//    freopen("milkvisits.in", "r", stdin);
//    freopen("milkvisits.out", "w", stdout);
    
    int n, q;
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(comp, 0, sizeof(comp));
    for (int i = 1; i <= n; i++) {
        if (comp[i] == 0) {
            dfs(i, i);
            curr_comp++;
        }
    }
    
    while (q--) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        
        if (comp[u] != comp[v] || s[u] == c) cout << 1;
        else cout << 0;
    }
    cout << '\n';
    
}
