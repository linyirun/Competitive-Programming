// http://www.usaco.org/index.php?page=viewproblem2&cpid=717.cpp
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define INF 1000000000000

const int MOD = 1000000007;
const int MAX = 101;

int n;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
bool is_safe(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//    freopen("visitfj.in", "r", stdin);
//    freopen("visitfj.out", "w", stdout);
    
    int t;
    cin >> n >> t;
    
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> cost[i][j];
    }
    
    // {x, y, # of squares passed}
    vector<vector<vector<ll>>> dist(n, vector<vector<ll>>(n, vector<ll>(3, INF)));
    
    dist[0][0][0] = 0;
    priority_queue<pair<pll, pii>, vector<pair<pll, pii>>, greater<pair<pll, pii>>> q;
    q.push({{0, 0}, {0, 0}});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        int x = p.second.first, y = p.second.second, turn = p.first.second;
        ll curr_cost = p.first.first;
        
        for (int i = 0; i < 4; i++) {
            int dest_x = x + dx[i], dest_y = y + dy[i];
            if (!is_safe(dest_x, dest_y)) continue;
            ll res_cost = curr_cost + t;
            if (turn == 2) res_cost += cost[dest_x][dest_y];
            if (res_cost < dist[dest_x][dest_y][(turn + 1) % 3]) {
                q.push({{res_cost, (turn + 1) % 3}, {dest_x, dest_y}});
                dist[dest_x][dest_y][(turn + 1) % 3] = res_cost;
            }
        }
    }
    
    cout << min({dist[n - 1][n - 1][0], dist[n - 1][n - 1][1], dist[n - 1][n - 1][2]}) << '\n';
    
}
