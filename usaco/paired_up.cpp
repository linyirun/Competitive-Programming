// http://www.usaco.org/index.php?page=viewproblem2&cpid=738
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007

#define INF 10000000


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = {y, x};
    }
    
    sort(a.begin(), a.end());
    
    int l = 0, r = n - 1;
    int mx = 0;
    while (l <= r) {
        if (a[l].second <= 0) l++;
        if (a[r].second <= 0) r--;
        if (l > r) break;
        int tmp = min(a[l].second, a[r].second);
        mx = max(mx, a[l].first + a[r].first);
        a[l].second -= tmp;
        a[r].second -= tmp;
    }
    cout << mx << '\n';
}
