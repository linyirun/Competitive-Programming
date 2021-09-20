// http://www.usaco.org/index.php?page=viewproblem2&cpid=863
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007

#define INF 10000000

vector<ll> a;
int n, k;

vector<ll> dp;

ll memo(int idx) {
    // a new team at this idx
    if (idx >= n) return 0;
    else if (dp[idx] != -1) return dp[idx];
    
    if (idx == 6) {
        cout;
    }
    ll curr_mx = 0;
    ll curr_best = 0;
    for (int i = idx; i < min(idx + k, n); i++) {
        curr_mx = max(curr_mx, a[i]);
        curr_best = max(curr_best, curr_mx * (i - idx + 1) + memo(i + 1));
    }
    return dp[idx] = curr_best;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("teamwork.in", "r", stdin);
    freopen("teamwork.out", "w", stdout);
    
    cin >> n >> k;
    
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    dp.resize(n);
    for (int i = 0; i < n; i++) dp[i] = -1;
    
    cout << memo(0) << '\n';
}
