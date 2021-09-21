// http://www.usaco.org/index.php?page=viewproblem2&cpid=945
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007

#define INF 1000000000

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("snakes.in", "r", stdin);
    freopen("snakes.out", "w", stdout);
    
    int n, num_changes;
    cin >> n >> num_changes;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // dp[idx][# of times left that you can change net size]
    
    vector<vector<ll>> dp(n + 1, vector<ll>(num_changes + 1, 0));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= num_changes; j++) {
            dp[i][j] = INF;
            ll curr_mx = 0, curr_sum = 0;
            for (int k = i; k < n; k++) {
                curr_mx = max(curr_mx, a[k]);
                curr_sum += a[k];
                int curr_sz = (k - i + 1);
                
                if (j == 0) {
                    if (k == n - 1) dp[i][j] = curr_mx * curr_sz - curr_sum;
                } else {
                    dp[i][j] = min(dp[i][j], curr_mx * curr_sz - curr_sum + dp[k + 1][j - 1]);
                }
            }
        }
    }
    
    
    cout << dp[0][num_changes] << '\n';
}
