// http://www.usaco.org/index.php?page=viewproblem2&cpid=673
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
const int MOD = 1000000009;

const int MAX = 1010;
const int MAXK = 11;
int n, m, k;
vector<vector<vector<ll>>> dp(MAX, vector<vector<ll>>(MAX, vector<ll>(MAXK, (ll) -1)));
vector<int> a, b;

vector<vector<vector<ll>>> pref(MAX, vector<vector<ll>>(MAX, vector<ll>(MAXK, -1)));

ll memo(int idx1, int idx2, int taken) {
    if (idx1 == n || idx2 == m) return !taken;
    else if (dp[idx1][idx2][taken] != -1) return dp[idx1][idx2][taken];
    ll cnt = memo(idx1 + 1, idx2, taken) + memo(idx1, idx2 + 1, taken) - memo(idx1 + 1, idx2 + 1, taken);
    cnt %= MOD;
    if (cnt < 0) cnt += MOD;
    
    if (taken && a[idx1] > b[idx2]) cnt = (cnt + memo(idx1 + 1, idx2 + 1, taken - 1)) % MOD;
//    cout << "dp[" << idx1 << "][" << idx2 << "][" << taken << "]: " << cnt << '\n';
    return dp[idx1][idx2][taken] = cnt;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    cout << memo(0, 0, k) << '\n';
    
    
}
/*
 2 2 1
 2 2
 1 1
 
 2 2 1
 2 2
 1 2
 answer is 2
 
 2 2 2
 4 4
 3 3
 
 */
