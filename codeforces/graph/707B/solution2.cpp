// https://codeforces.com/problemset/problem/707/B
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n; // 10^5 
int m; // 10^5
int k; // 10^5

bool isFlourIn[100'005];
int edge[100'005][3]; // from to length

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        edge[i][0] = u;
        edge[i][1] = v;
        edge[i][2] = l;
    }
    for (int i = 0; i < k; i++) {
        int city;
        cin >> city;
        isFlourIn[city] = true;
    }
    int ans = 1'000'000'001;
    for (int i = 0; i < m; i++) {
        if (isFlourIn[edge[i][0]] ^ isFlourIn[edge[i][1]]) {
            ans = min(ans, edge[i][2]);
        }
    }
    if (ans == 1'000'000'001) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}