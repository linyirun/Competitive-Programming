// http://www.usaco.org/index.php?page=viewproblem2&cpid=833
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
using namespace std;
 
#define MOD 1000000007
#define INF 10000000

vector<vector<int>> adj;

int c1, c2;
int d1 = -10000, d2 = -10000;

void find_child(int node, int depth) {
    if (node == c1) {
        d1 = depth;
    }
    else if (node == c2) {
        d2 = depth;
    }
    for (int child : adj[node]) find_child(child, depth + 1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
//    freopen("family.in", "r", stdin);
//    freopen("family.out", "w", stdout);
    
    map<string, int> to_i;
    map<int, string> to_s;
    
    int n;
    cin >> n;
    string tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    
    adj.resize(n + 2);
    int curr_id = 0;
    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;
        
        if (!to_i.count(u)) {
            to_i[u] = curr_id;
            to_s[curr_id++] = u;
        }
        if (!to_i.count(v)) {
            to_i[v] = curr_id;
            to_s[curr_id++] = v;
        }
        
        adj[to_i[u]].push_back(to_i[v]);
    }
    
    if (!to_i.count(tmp1) || !to_i.count(tmp2)) {
        cout << "NOT RELATED";
        return 0;
    }
    
    c1 = to_i[tmp1], c2 = to_i[tmp2];
    
    find_child(c1, 0);
    if (d2 > 0) {
        cout << to_s[c1] << " is the ";
        for (int i = d2 - 1; i >= 0; i--) {
            if (i == 0) cout << "mother ";
            else if (i == 1) cout << "grand-";
            else cout << "great-";
        }
        cout << "of " << to_s[c2] << '\n';
        return 0;
    }
    
    d1 = -10000;
    find_child(c2, 0);
    if (d1 > 0) {
        cout << to_s[c2] << " is the ";
        for (int i = d1 - 1; i >= 0; i--) {
            if (i == 0) cout << "mother ";
            else if (i == 1) cout << "grand-";
            else cout << "great-";
        }
        cout << "of " << to_s[c1] << '\n';
        return 0;
    }
    
    // siblings
    for (int i = 0; i <= n; i++) {
        d1 = -10000, d2 = -10000;
        find_child(i, 0);
        
        if (d1 == d2 && d1 == 1) {
            cout << "SIBLINGS\n";
            return 0;
        }
    }
    
    // aunt
    for (int i = 0; i <= n; i++) {
        d1 = -10000, d2 = -10000;
        find_child(i, 0);
        if (d1 == 1 && d2 > 0) {
            cout << to_s[c1] << " is the ";
            for (int i = d2 - 2; i >= 0; i--) {
                if (i == 0) cout << "aunt ";
                else cout << "great-";
            }
            cout << "of " << to_s[c2] << '\n';
            return 0;
        } else if (d2 == 1 && d1 > 0) {
            cout << to_s[c2] << " is the ";
            for (int i = d1 - 2; i >= 0; i--) {
                if (i == 0) cout << "aunt ";
                else cout << "great-";
            }
            cout << "of " << to_s[c1] << '\n';
            return 0;
        }
    }
    
    // just related
    for (int i = 0; i <= n; i++) {
        d1 = -10000, d2 = -10000;
        find_child(i, 0);
        if (d1 >= 0 && d2 >= 0) {
            cout << "COUSINS\n";
            return 0;
        }
    }
    cout << "NOT RELATED\n";
}
