// https://dmoj.ca/problem/cco20p1
#include <bits/stdc++.h>

using ld = long double;
using namespace std;

/*
 Idea: sorting + 2 pointers
 Make 2 vectors, start and end
 Calculate the start and end of each friend's vision
 Let x1 = left bound, x2 = right bound
 If x1 > x2, don't do anything
 Otherwise, add x1 to the start array, x2 to the end array
 
 Store the size of start into size
 
 Add INT_MAX to both the start and end array, then sort both arrays
 
 Make variables cnt and curr, indicating how many friends can see him, and current time
 To begin, curr = start[0], cnt = 1
 
 Make a freq array freq[n + 1] = 0
 
 ptr1 = start ptr, ptr2 = end ptr
 Initially, ptr1 = 1, ptr2 = 0
 Start looping:
    if ptr1 >= size && ptr2 >= size:
        break
    while true:
        if start[ptr1] == curr:
            cnt++
            ptr1++
        
        if end[ptr2] == curr:
            cnt--
            ptr2++
    int next = min(start[ptr1], end[ptr2])
    freq[cnt] +=
    curr = next
    
 
 Note: The ending point has to +1 to not be inclusive
 */


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int L, R, Y;
    cin >> L >> R >> Y;
    
    vector<int> start, end;
    for (int i = 0; i < n; i++) {
        int x;
        ld v, h;
        cin >> x >> v >> h;
        
        int st = max(L, (int) round(ceil(-(Y * h) / v + 0.001)) + x);
        int ed = min(R + 1, (int) round(floor(Y * h / v - 0.001)) + x + 1);
        
        if (st >= ed) continue;
        start.push_back(st);
        end.push_back(ed);
    }
    
    start.push_back(L);
    start.push_back(INT_MAX);
    end.push_back(R + 1);
    end.push_back(INT_MAX);
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    
    int freq[n + 1];
    memset(freq, 0, sizeof(freq));
    
    int sz = (int) start.size() - 2;
    
    int cnt = -1, curr = start[0];
    int ptr1 = 0, ptr2 = 0;
    while (true) {
        if (ptr1 >= sz && ptr2 >= sz) break;
        
        while (start[ptr1] == curr) {
            ptr1++;
            cnt++;
        }
        while (end[ptr2] == curr) {
            ptr2++;
            cnt--;
        }
        
        int next = min(start[ptr1], end[ptr2]);
        freq[cnt] += next - curr;
        curr = next;
    }
    
    for (int i = 0; i <= n; i++) {
        if (i) freq[i] += freq[i - 1];
        cout << freq[i] << "\n";
    }
    
}
