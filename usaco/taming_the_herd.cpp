// http://www.usaco.org/index.php?page=viewproblem2&cpid=815
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007

const int INF = 10000;

const int MAX = 101;
vector<int> a;
int dp[MAX][MAX][MAX];
int n;

int memo(int idx, int cnt, int days) {
    if (idx == n && cnt != 0) return INF;
    else if (idx >= n) return 0;
    if (dp[idx][cnt][days] != -1) return dp[idx][cnt][days];
    
    int curr_best = memo(idx + 1, cnt, days + 1) + (a[idx] != days); // dont put breakout here
    if (cnt && idx) curr_best = min(curr_best, memo(idx + 1, cnt - 1, 1) + (a[idx] != 0));
    return dp[idx][cnt][days] = curr_best;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(dp, -1, sizeof(dp));
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        cout << memo(0, i, 0) << '\n';
    }
}

