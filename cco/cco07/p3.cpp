// https://dmoj.ca/problem/cco07p3
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define ll long long
#define ld long double

#define MOD 1000000007

using namespace std;

#define MAX 200000
#define INF 10000000

int main() {
    fastIO;
    
    int tt;
    cin >> tt;
    
    const int added = 10;
    
    while (tt--) {
        int n, k, w;
        cin >> n >> k >> w;
        
        int sz = n * 2 * w + added;
        int dp[sz][k + 1][2];
        memset(dp, 0, sizeof(dp));
        
        vector<int> a(sz), pref(sz);
        for (int i = w + 1; i < w + n + 1; i++) {
            cin >> a[i];
            pref[i] = a[i] + pref[i - 1];
        }
        
        for (int i = w + n + 1; i < sz; i++) pref[i] += pref[i - 1];
        
        for (int idx = n + w; idx >= 0; idx--) {
            for (int ball = 1; ball <= k; ball++) {
                if (ball == 1) {
                    dp[idx][ball][1] = pref[idx + w - 1];
                    if (idx) dp[idx][ball][1] -= pref[idx - 1];
                    dp[idx][ball][0] = max(dp[idx][ball][1], dp[idx + 1][ball][0]);
                    
//                    cout << "dp[" << idx << "][" << ball << "][0]: " << dp[idx][ball][0] << '\n';
//                    cout << "dp[" << idx << "][" << ball << "][1]: " << dp[idx][ball][1] << '\n';
                    continue;
                }
                
                dp[idx][ball][0] = dp[idx][ball][1] = -INF;
                int curr_sum = a[idx];
                for (int i = idx + 1; i < idx + w; i++) {
                    dp[idx][ball][1] = max(dp[idx][ball][1], curr_sum + dp[i][ball - 1][1]);
                    curr_sum += a[i];
                }
                dp[idx][ball][1] = max(dp[idx][ball][1], curr_sum + dp[idx + w][ball - 1][0]); // hit all pins
                dp[idx][ball][0] = max(dp[idx + 1][ball][0], dp[idx][ball][1]);
                

            }
        }
        
        cout << dp[0][k][0] << '\n';
    }
}
/*
 1
 5 1 2
 -5 7 -5 -5 -5
 
 1
 5 2 2
 -1 5 -3 6 -100
 */
