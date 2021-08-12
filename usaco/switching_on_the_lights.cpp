// http://www.usaco.org/index.php?page=viewproblem2&cpid=570

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000
#define MAX 101
int n, m;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
bool vis[MAX][MAX];
bool is_lit[MAX][MAX];
vector<pii> lights[MAX][MAX];

bool is_safe(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < n;
}

void dfs(int row, int col) {
    vis[row][col] = true;
    // turn on all the lights
    for (pii p : lights[row][col]) {
        is_lit[p.first][p.second] = true;
        if (vis[p.first][p.second]) continue;
        for (int i = 0; i < 4; i++) {
            int destX = p.first + dx[i], destY = p.second + dy[i];
            if (is_safe(destX, destY) && vis[destX][destY]) {
                dfs(p.first, p.second);
                break;
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        int destX = row + dx[i], destY = col + dy[i];
        if (is_safe(destX, destY) && !vis[destX][destY] && is_lit[destX][destY]) {
            dfs(destX, destY);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//        freopen("lightson.in", "r", stdin);
//        freopen("lightson.out", "w", stdout);

    cin >> n >> m;
    memset(is_lit, false, sizeof(is_lit));
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        lights[x - 1][y - 1].push_back({a - 1, b - 1});
    }
    is_lit[0][0] = true;
    dfs(0, 0);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += is_lit[i][j];
        }
    }
    cout << cnt << '\n';
}
