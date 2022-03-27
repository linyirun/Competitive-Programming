#include <bits/stdc++.h>
#define ll long long int
#define ld long double

using namespace std;
typedef pair<int, int> pii;

int t;
int wins = 0;
void recur(vector<int> &scores, int game, vector<vector<bool>> &played) {
    if (game == 7) {
        bool isHighest = true;
        for (int i = 0; i < 4; i++) {
            if (i == t) continue;
            if (scores[i] >= scores[t]) isHighest = false;
        }
        if (isHighest) wins++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (played[i][j]) continue;
            played[i][j] = true;

            scores[i] += 3;
            recur(scores, game + 1, played);
            scores[i] -= 3;

            // draw
            scores[i]++, scores[j]++;
            recur(scores, game + 1, played);
            scores[i]--, scores[j]--;

            // loss
            scores[j] += 3;
            recur(scores, game + 1, played);
            scores[j] -= 3;
            played[i][j] = false;
            goto d;
        }
    }
    d:;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int g;
    cin >> t >> g;
    t--;
    vector<int> scores(4, 0);
    vector<vector<bool>> played(4, vector<bool>(4, true));
    played[0][1] = played[0][2] = played[0][3] =
            played[1][2] = played[1][3] = played[2][3] = false;
    for (int i = 0; i < g; i++) {
        int a, b, sA, sB;
        cin >> a >> b >> sA >> sB;
        a--, b--;
        played[min(a, b)][max(a, b)] = true;
        if (sA > sB) scores[a] += 3;
        else if (sA == sB) scores[a]++, scores[b]++;
        else scores[b] += 3;
    }
    recur(scores, g + 1, played);
    cout << wins;

}
