// http://www.usaco.org/index.php?page=viewproblem2&cpid=1134
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000
#define MAX 25

bool vis[MAX][MAX][20000];
set<int> wins;

string grid[MAX][MAX];

int hsh(vector<vector<char>> &curr_grid) {
    int curr = 1;
    int curr_hash = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (curr_grid[i][j] == 'M') curr_hash += curr;
            else if (curr_grid[i][j] == 'O') curr_hash += 2 * curr;
            curr *= 3;
        }
    }
    return curr_hash;
}

bool check_win(vector<vector<char>> &curr_grid) {
    for (int i = 0; i < 3; i++) {
        if (curr_grid[i][0] == 'M' && curr_grid[i][1] == 'O' && curr_grid[i][2] == 'O') return true;
        if (curr_grid[i][0] == 'O' && curr_grid[i][1] == 'O' && curr_grid[i][2] == 'M') return true;
        if (curr_grid[0][i] == 'M' && curr_grid[1][i] == 'O' && curr_grid[2][i] == 'O') return true;
        if (curr_grid[0][i] == 'O' && curr_grid[1][i] == 'O' && curr_grid[2][i] == 'M') return true;
    }
    
    // diagonals
    if (curr_grid[0][0] == 'M' && curr_grid[1][1] == 'O' && curr_grid[2][2] == 'O') return true;
    if (curr_grid[0][0] == 'O' && curr_grid[1][1] == 'O' && curr_grid[2][2] == 'M') return true;
    
    if (curr_grid[2][0] == 'M' && curr_grid[1][1] == 'O' && curr_grid[0][2] == 'O') return true;
    if (curr_grid[2][0] == 'O' && curr_grid[1][1] == 'O' && curr_grid[0][2] == 'M') return true;
    return false;
}

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void dfs(int row, int col, vector<vector<char>> curr_grid) {
    int curr_hash = hsh(curr_grid);
    vis[row][col][curr_hash] = true;
    
    if (grid[row][col][0] == 'M' || grid[row][col][0] == 'O') {
        int tmpx = (grid[row][col][1] - '1'), tmpy = (grid[row][col][2] - '1');
        if (curr_grid[tmpx][tmpy] == '.') {
            if (grid[row][col][0] == 'M') curr_grid[tmpx][tmpy] = 'M';
            else curr_grid[tmpx][tmpy] = 'O';
        }
    }
    
    curr_hash = hsh(curr_grid);
    
    if (check_win(curr_grid)) {
        wins.insert(curr_hash);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int dest_x = row + dx[i], dest_y = col + dy[i];
        if (grid[dest_x][dest_y][0] != '#' && !vis[dest_x][dest_y][curr_hash]) {
            dfs(dest_x, dest_y, curr_grid);
        }
    }
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//        freopen("snowboots.in", "r", stdin);
//        freopen("snowboots.out", "w", stdout);
    memset(vis, false, sizeof(vis));
    
    int n;
    cin >> n;
    int start_x = 0, start_y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c1, c2, c3;
            cin >> c1 >> c2 >> c3;
            string s;
            s += c1, s += c2, s += c3;
            grid[i][j] = s;
            if (c1 == 'B') {
                start_x = i, start_y = j;
            }
        }
    }
    vector<vector<char>> nothing(3, vector<char>(3, '.'));
    dfs(start_x, start_y, nothing);
    
//    for (int i : wins) cout << i << '\n';
    cout << wins.size() << '\n';
}

/*
 MOO M.. M.. O..
 ... O.. .O. .O.
 ... O.. ..O ..M
 */
