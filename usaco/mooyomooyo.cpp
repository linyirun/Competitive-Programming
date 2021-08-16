// http://www.usaco.org/index.php?page=viewproblem2&cpid=860
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000
#define MAX 101

int grid[MAX][10];
bool vis[MAX][10];
vector<pii> curr;
int cnt = 0;

int n, k;

bool is_safe(int row, int col) {
    return row >= 0 && row < n && col >= 0 && col < 10;
}


int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int row, int col, int curr_col) {
    vis[row][col] = true;
    curr.push_back({row, col});
    
    cnt++;
    for (int i = 0; i < 4; i++) {
        int dest_x = row + dx[i], dest_y = col + dy[i];
        if (is_safe(dest_x, dest_y) && !vis[dest_x][dest_y] && grid[dest_x][dest_y] == curr_col) {
            dfs(dest_x, dest_y, curr_col);
        }
    }
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//        freopen("mooyomooyo.in", "r", stdin);
//        freopen("mooyomooyo.out", "w", stdout);
    cin >> n >> k;
    
    memset(grid, 0, sizeof(grid));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }
    
    
    while (true) {
        bool has_moved = false;
        
        memset(vis, false, sizeof(vis));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    curr.clear();
                    cnt = 0;
                    dfs(i, j, grid[i][j]);
                    if (cnt >= k) {
                        has_moved = true;
                        for (pii p : curr) {
                            grid[p.first][p.second] = 0;
                        }
                    }
                }
            }
        }
        

        
        // simulate gravity
        for (int col = 0; col < 10; col++) {
            int zero_pos = -1;
            for (int row = n - 1; row >= 0; row--) {
                if (grid[row][col]) {
                    if (zero_pos < row) continue;
                    grid[zero_pos][col] = grid[row][col];
                    grid[row][col] = 0;
                    zero_pos--;
                } else {
                    zero_pos = max(zero_pos, row);
                }
            }
        }
        if (!has_moved) break;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    
}
