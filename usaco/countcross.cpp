// http://www.usaco.org/index.php?page=viewproblem2&cpid=716
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000
#define MAX 101

bool has[MAX][MAX];
bool vis[MAX][MAX];

vector<pii> adj[MAX][MAX];
int n;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool is_safe(int row, int col) {
    return row >= 1 && row <= n && col >= 1 && col <= n;
}

int cnt = 0;
void dfs(int row, int col) {
    vis[row][col] = true;
    if (has[row][col]) cnt++;
    
    for (int i = 0; i < 4; i++) {
        int dest_x = row + dx[i], dest_y = col + dy[i];
        
        if (!is_safe(dest_x, dest_y)) continue;
        bool can = true;
        for (pii p : adj[row][col]) {
            if (p.first == dest_x && p.second == dest_y) can = false;
        }
        if (can && !vis[dest_x][dest_y]) {
            dfs(dest_x, dest_y);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//        freopen("countcross.in", "r", stdin);
//        freopen("countcross.out", "w", stdout);
    
    memset(has, false, sizeof(has));
    memset(vis, false, sizeof(vis));
    
    int k, r;
    cin >> n >> k >> r;
    
    for (int i = 0; i < r; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        adj[x1][y1].push_back({x2, y2});
        adj[x2][y2].push_back({x1, y1});
    }
    
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        has[row][col] = true;
    }
    
    vector<int> components;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!vis[i][j]) {
                cnt = 0;
                dfs(i, j);
                if (cnt != 0) components.push_back(cnt);
            }
        }
    }
    
    ll ans = 0;
    for (int i : components) {
        ans += i * (k - i);
    }
    
    cout << ans / 2 << '\n';
}
