// http://www.usaco.org/index.php?page=viewproblem2&cpid=694
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
    
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    
    int n, choices_left;
    cin >> n >> choices_left;
    
    vector<int> a(n);
    // 0 is hoof, 1 is scissors, 2 is paper
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'H') a[i] = 0;
        else if (c == 'S') a[i] = 1;
        else a[i] = 2;
    }
    
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(choices_left + 1, vector<int>(3, 0)));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= choices_left; j++) {
            for (int choice = 0; choice < 3; choice++) {
                int curr = 0;
                // win
                if (((choice + 1) % 3) == a[i]) curr++;
                
                dp[i][j][choice] = curr + dp[i + 1][j][choice];
                if (j) {
                    dp[i][j][choice] = max({dp[i][j][choice], curr + dp[i + 1][j - 1][0], curr + dp[i + 1][j - 1][1], curr + dp[i + 1][j - 1][2]});
                }
            }
        }
    }
    
    cout << max({dp[0][choices_left][0], dp[0][choices_left][1], dp[0][choices_left][2]}) << '\n';
}
