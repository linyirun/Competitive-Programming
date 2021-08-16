// http://www.usaco.org/index.php?page=viewproblem2&cpid=1110
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000
#define MAX 2001

bool has[MAX][MAX];
int cnt[MAX][MAX];

set<pii> added;
set<pii> need; // set of nodes w/ cnt == 3

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

void add_point(int x, int y) {
    has[x][y] = true;
    if (cnt[x][y] == 3) need.insert({x, y});
    
    for (int i = 0; i < 4; i++) {
        int dest_x = x + dx[i], dest_y = y + dy[i];
        cnt[dest_x][dest_y]++;
        if (has[dest_x][dest_y]) {
            if (cnt[dest_x][dest_y] == 4) need.erase({dest_x, dest_y});
            else if (cnt[dest_x][dest_y] == 3) need.insert({dest_x, dest_y});
        }
    }
}

void process_point(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int dest_x = x + dx[i], dest_y = y + dy[i];
        if (!has[dest_x][dest_y]) {
            added.insert({dest_x, dest_y});
            add_point(dest_x, dest_y);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//        freopen("mooyomooyo.in", "r", stdin);
//        freopen("mooyomooyo.out", "w", stdout);
    
    int n;
    cin >> n;
    
    int ans[n];
    memset(has, false, sizeof(has));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;
        
        if (added.count({x, y})) {
            added.erase({x, y});
        } else {
            add_point(x, y);
            while (!need.empty()) {
                pii point = *need.begin();
                need.erase(need.begin());
                process_point(point.first, point.second);
            }
        }
        ans[i] = added.size();
    }
    
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    
}
/*
 make a set "added" -> stores the set of added coords
 if a new dot is in the set of the added coords, dec count by 1
 
 keep a set of points with 3 neighbors
 
 */
