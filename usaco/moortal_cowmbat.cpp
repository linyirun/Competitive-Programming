// http://www.usaco.org/index.php?page=viewproblem2&cpid=971
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007

const int MAXM = 27;
const int MAX = 105000;
const ll INF = 10000000000;
int n, m, needed;
vector<vector<ll>> cost(MAXM, vector<ll>(MAXM, INF));
vector<vector<ll>> pref(MAX, vector<ll>(MAXM, INF));
// pref[idx][letter] - cost to make a prefix of the string that one letter

vector<vector<ll>> dp(MAX, vector<ll>(MAXM, (ll) -1));
string s;
vector<int> a;

ll memo(int idx, int c_before) {
    if (idx >= n) return 0;
    else if (dp[idx][c_before] != -1) return dp[idx][c_before];
    
    ll best = INF;
    if (idx) best = min(best, cost[a[idx]][c_before] + memo(idx + 1, c_before));
    // take a prefix
    if (idx + needed <= n) {
        for (int new_letter = 0; new_letter < m; new_letter++) {
            ll cost_to_change = pref[idx + needed - 1][new_letter];
            if (idx) cost_to_change -= pref[idx - 1][new_letter];
            best = min(best, cost_to_change + memo(idx + needed, new_letter));
        }
    }
    return dp[idx][c_before] = best;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);
    
    cin >> n >> m >> needed >> s;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = (s[i] - 'a');
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }
    
    // floyd-warshall
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n) pref[i][j] = cost[a[i]][j];
            else pref[i][j] = 0;
            if (i) pref[i][j] += pref[i - 1][j];
        }
    }
    
    cout << memo(0, 0) << '\n';
    
}

