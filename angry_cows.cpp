#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000

int n;
vector<ll> a;

pair<bool, bool> possible(ll curr_pos, ll rad) {
    // {can reach left, can reach rightmost}
    
    ll l_ptr = lower_bound(a.begin(), a.end(), curr_pos - rad) - a.begin();
    // radius left, previous position
    ll rad_left = rad - 2, prev = a[l_ptr];
    
    while (l_ptr > 0) {
        if (prev - a[l_ptr - 1] > rad_left) {
            if (prev == a[l_ptr]) return {false, false};
            rad_left -= 2;
            prev = a[l_ptr];
        } else l_ptr--;
    }
    
    ll r_ptr = upper_bound(a.begin(), a.end(), curr_pos + rad) - a.begin() - 1;
    if (r_ptr == -1) return {true, true};
    else {
        rad_left = rad - 2, prev = a[r_ptr];
        while (r_ptr < n - 1) {
            if (a[r_ptr + 1] - prev > rad_left) {
                if (prev == a[r_ptr]) return {true, false};
                rad_left -= 2;
                prev = a[r_ptr];
            } else r_ptr++;
        }
    }
    
    return {true, true};
}

bool check(ll rad) {
    ll l = a[0], r = a[n - 1];
    for (int i = 0; i < 50; i++) {
        ll mp = (l + r) / 2;
        auto res = possible(mp, rad);
        if (res.first == res.second && res.first == true) return true;
        else if (!res.first) r = mp; // move left
        else l = mp; // move to the right
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//     freopen("angry.in", "r", stdin);
//     freopen("angry.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());
    
    ll l = 0, r = 2e9;
    ll ans = 0;
    while (l <= r) {
        ll mp = (l + r) / 2;
        if (check(mp)) {
            ans = mp;
            r = mp - 1;
        } else l = mp + 1;
    }
    cout.precision(1);
    cout << fixed << (ld) ans / 2 << '\n';
    
}

/*
 multiply everything by 2 to not deal with decimals
 */

