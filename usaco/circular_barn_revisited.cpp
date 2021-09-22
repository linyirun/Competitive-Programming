// http://www.usaco.org/index.php?page=viewproblem2&cpid=622
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007

#define INF 100000000

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("cbarn2.in", "r", stdin);
    freopen("cbarn2.out", "w", stdout);
    
    int n, mx_doors;
    cin >> n >> mx_doors;
    mx_doors--;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll best = LLONG_MAX;
    for (int count_shift = 0; count_shift < n; count_shift++) {
        // dp
        vector<vector<ll>> dp(n + 1, vector<ll>(mx_doors + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= mx_doors; j++) {
                dp[i][j] = LLONG_MAX;
                ll total = 0;
                for (int k = i; k < n; k++) {
                    total += a[k] * (k - i);
                    if (j) dp[i][j] = min(dp[i][j], total + dp[k + 1][j - 1]);
                    else if (k == n - 1) dp[i][j] = total;
                }
            }
        }
        
        vector<ll> new_arr(n);
        for (int i = 0; i < n; i++) {
            new_arr[i] = a[(i + 1) % n];
        }
        a = new_arr;
        best = min(best, dp[0][mx_doors]);
    }
    cout << best << '\n';
}

/*
 6 2
 4 2 6 2 2 5
 */
