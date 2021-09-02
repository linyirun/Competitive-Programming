// http://www.usaco.org/index.php?page=viewproblem2&cpid=763
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
    
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    
    ll n, g;
    cin >> n >> g;
    
    map<int, ll> prod;
    
    vector<pair<int, pii>> delta(n);
    
    multiset<ll> ms;
    for (int i = 0; i < n; i++) {
        int day, id, change;
        cin >> day >> id >> change;
        delta[i] = {day, {id, change}};
        prod[id] = g;
        ms.insert(g);
    }

    sort(delta.begin(), delta.end());
    
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        ll last = *(--ms.end());
        int id = delta[i].second.first, change = delta[i].second.second;
        
        if (prod[id] == last) {
            if (*(--ms.end()) == *(----ms.end()) && change > 0) cnt++; // tiebreaker -> increased top in a tie
            else if (*(--ms.end()) + change <= *(----ms.end()) && change < 0) cnt++; // top element stays top after a decrease
        } else if (prod[id] + change >= last) cnt++;
        
        ms.erase(ms.find(prod[id]));
        prod[id] += change;
        ms.insert(prod[id]);
    }
    cout << cnt << '\n';
}
