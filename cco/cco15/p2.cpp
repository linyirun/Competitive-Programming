// https://dmoj.ca/problem/cco15p2
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pii pair<int, int>
#define ll long long
#define ld long double

using namespace std;
#define MAX 18

int main() {
    fastIO;

    int n, m;
    cin >> n >> m;
    int adj[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = -1000000;
    }

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u][v] = cost;
    }

    int dp[n][1 << n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 1 << n; j++) {
            if (i) dp[i][j] = -1000000;
            else dp[0][j] = 0;
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int node = 0; node < n; node++) {
            if (mask & (1 << node)) continue;
            int tmp = mask ^ (1 << node);
            for (int dest = 0; dest < n; dest++) {
                if (adj[node][dest] > 0 && !(mask & (1 << dest))) {
                    dp[dest][tmp] = max(dp[dest][tmp], dp[node][mask] + adj[node][dest]);
                }
            }
        }
    }

    int best = 0;
    for (int i = 0; i < 1 << n; i++) {
        best = max(best, dp[n - 1][i]);
    }
    
    cout << best << "\n";
}
