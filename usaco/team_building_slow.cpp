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

ll memo2(int idx1, int idx2, int taken);
ll memo(int idx1, int idx2, int taken) {
    if (taken == 0) return 1;
    else if (idx1 > n || idx2 > m) return 0;
    else if (dp[idx1][idx2][taken] != -1) return dp[idx1][idx2][taken];
    ll cnt = 0;
    
//     for (int i = idx2; i <= m; i++) {
//      if (a[idx1] > b[i]) cnt = (cnt + memo(idx1 + 1, i + 1, taken - 1)) % MOD; // pair up
//     }
    int first_pos = max(idx2 + 1, (int) (lower_bound(b.begin(), b.end(), a[idx1]) - b.begin() + 1));
    cnt = (cnt + max(0LL, memo2(idx1 + 1, idx2 + 1, taken - 1) - memo2(idx1 + 1, first_pos, taken - 1))) % MOD;
    
    
    // dont pair - skip
    cnt = (cnt + memo(idx1 + 1, idx2, taken)) % MOD;
//    cnt = (cnt + memo(idx1, idx2 + 1, taken)) % MOD;
    
    return dp[idx1][idx2][taken] = cnt;
}

ll memo2(int idx1, int idx2, int taken) {
    if (pref[idx1][idx2][taken] != -1) return pref[idx1][idx2][taken];
    ll res = 0;
    if (idx2 > m + 1) return 0;
    if (taken == 0) {
        res = 1;
        if (idx2 <= m) return pref[idx1][idx2][taken] = res + memo2(idx1, idx2 + 1, taken);
        else return pref[idx1][idx2][taken] = res;
    } else if (idx1 > n || idx2 > m) {
        return 0;
    } else if (pref[idx1][idx2][taken] != -1) return pref[idx1][idx2][taken];
    return pref[idx1][idx2][taken] = memo(idx1, idx2, taken) + memo2(idx1, idx2 + 1, taken);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//    freopen("team.in", "r", stdin);
//    freopen("team.out", "w", stdout);
    
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    a.push_back(0);
    b.push_back(0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
//    for (int idx1 = n; idx1 >= 0; idx1--) {
//        for (int idx2 = m; idx2 >= 0; idx2--) {
//            pref[idx1][idx2][0] = 1 + pref[idx1][idx2 + 1][0];
//        }
//    }
    
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= m; j++) {
//            for (int kk = 0; kk <= k; kk++) {
//                cout << "dp[" << i << "][" << j << "][" << kk << "]: " << dp[i][j][kk] << '\n';
//            }
//        }
//    }
    
    cout << memo(1, 1, k) << '\n';
    
    
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

