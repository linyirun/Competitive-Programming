// http://www.usaco.org/index.php?page=viewproblem2&cpid=740
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000
#define MAX 21

vector<pair<pii, pii>> done;
int n;

bool vis[MAX][MAX];
vector<vector<char>> grid;

int x, y, x2, y2;
bool contained(pair<pii, pii> check) {
    int x = check.first.first, y = check.first.second, x2 = check.second.first, y2 = check.second.second;
    for (auto p : done) {
        if (p == check) continue;
        if (p.first.first <= x && p.first.second <= y && p.second.first >= x2 && p.second.second >= y2) return true;
    }
    return false;
}

bool is_safe(int row, int col) {
    return row >= x && row <= x2 && col >= y && col <= y2;
}

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int row, int col, char curr) {
    vis[row][col] = true;
    for (int i = 0; i < 4; i++) {
        int dest_x = row + dx[i], dest_y = col + dy[i];
        if (is_safe(dest_x, dest_y) && !vis[dest_x][dest_y] && grid[dest_x][dest_y] == curr) dfs(dest_x, dest_y, curr);
    }
}


// check if this rectangle is good
bool check() {
    map<char, int> mp;
    memset(vis, false, sizeof(vis));
    for (int row = x; row <= x2; row++) {
        for (int col = y; col <= y2; col++) {
            if (!vis[row][col]) {
                dfs(row, col, grid[row][col]);
                mp[grid[row][col]]++;
            }
        }
    }
    
    int first = (*mp.begin()).second;
    int sec = (*mp.rbegin()).second;
    
    if (mp.size() != 2) return false;
    if ((first == 1 && sec >= 2) || (first >= 2 && sec == 1)) {
        return true;
    }
    return false;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//        freopen("where.in", "r", stdin);
//        freopen("where.out", "w", stdout);
    
    cin >> n;
    grid = vector<vector<char>>(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    for (int r_size = n - 1; r_size >= 0; r_size--) {
        for (int c_size = n - 1; c_size >= 0; c_size--) {
            for (int i = 0; i + r_size < n; i++) {
                for (int j = 0; j + c_size < n; j++) {
                    x = i, x2 = i + r_size, y = j, y2 = j + c_size;
                    if (check()) {
                        done.push_back({{x, y}, {x2, y2}});
                    }
                }
            }
        }
    }
    
    int to_remove = 0;
    for (auto p : done) {
        if (contained(p)) to_remove++;
    }
    
    cout << done.size() - to_remove << '\n';
}
