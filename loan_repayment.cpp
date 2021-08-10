#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000

ll n, k, m;
bool check(ll x) {
    ll paid = 0;
    ll day = 0;
    while (day < k && paid < n) {
        ll y = (n - paid) / x;
        if (y < m) {
            ll days_left = k - day;
            return paid + m * days_left >= n;
        }
        
        ll days_passed = max(1LL, (n - paid - x * y + y - 1) / y);
        days_passed = min(days_passed, k - day);
        day = min(k, days_passed + day);
        paid += y * days_passed;
    }
    return paid >= n;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//     freopen("loan.in", "r", stdin);
//     freopen("loan.out", "w", stdout);
    
    cin >> n >> k >> m;
    
    // binsearch
    
    ll l = 2, r = 1e12;
    ll ans = 1;
    while (l <= r) {
        ll mp = (l + r) / 2;
        
        if (check(mp)) {
            ans = mp;
            l = mp + 1;
        } else r = mp - 1;
    }
    cout << ans << '\n';
    
 }

// 1000000000000 1000000000000 1
