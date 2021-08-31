// http://www.usaco.org/index.php?page=viewproblem2&cpid=834
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
    
//    freopen("sort.in", "r", stdin);
//    freopen("sort.out", "w", stdout);
    
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pii> sorted(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sorted[i] = {a[i], i};
    }

    sort(sorted.begin(), sorted.end());
    int mx = 0;
    for (int i = 0; i < n; i++) {
        pii to_find = {a[i], i};
        mx = max(mx, i - (int) (lower_bound(sorted.begin(), sorted.end(), to_find) - sorted.begin()));
    }

    cout << mx + 1 << '\n';
    
    
}

/*
 7
 7 7 6 5 4 3 2
 
 answer is 7
 */
