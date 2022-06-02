// https://codeforces.com/problemset/problem/707/B
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n; // 10^5 
int m; // 10^5
int k; // 10^5

int flourCity[100'005];

struct Node {
    vector<int> adj;
    vector<int> length;
    bool isFlour = false;
};
Node graph[100'005];

int main() {
    cin >> n >> m >> k;
    while (m--) {
        int u, v, l;
        cin >> u >> v >> l;
        graph[u].adj.push_back(v);
        graph[u].length.push_back(l);
        graph[v].adj.push_back(u);
        graph[v].length.push_back(l);
    }
    int ans = 1'000'000'001;
    for (int i = 0; i < k; i++) {
        int city;
        cin >> city;
        graph[city].isFlour = true;
        flourCity[i] = city;
    }

    for (int i = 0; i < k; i++) {
        int city = flourCity[i];
        for (int j = 0; j < graph[city].adj.size(); j++) {
            int nextNode = graph[city].adj[j];
            if (!graph[nextNode].isFlour)
                ans = min(graph[city].length[j], ans);
        }
    }
    if (ans == 1'000'000'001) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}