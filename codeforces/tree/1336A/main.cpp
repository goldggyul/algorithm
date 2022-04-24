#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
https://codeforces.com/problemset/problem/1336/A
*/

int n, k;
struct Node {
    int pt;
    vector<int> adj;
};
Node tree[200'001];
int happy[200'001];
int idx = 0;

void setParent(int s, int pt) {
    Node& cur = tree[s];
    cur.pt = pt;
    for (int i = 0; i < cur.adj.size(); i++) {
        if (cur.adj[i] != cur.pt) {
            setParent(cur.adj[i], s);
        }
    }
}

int dfs(int s, int depth) {
    int descCnt = 0;
    // 루트 까지의 거리 - 아래 child 개수
    Node& cur = tree[s];
    for (int i = 0; i < cur.adj.size(); i++) {
        if (cur.adj[i] != cur.pt) {
            descCnt += dfs(cur.adj[i], depth + 1) + 1;
        }
    }
    happy[idx++] = depth - descCnt;
    return descCnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].adj.push_back(v);
        tree[v].adj.push_back(u);
    }

    setParent(1, 0);
    dfs(1, 0);

    sort(happy, happy + n, greater<int>());
    long long happySum = 0;
    for (int i = 0; i < k; i++) {
        happySum += happy[i];
    }
    cout << happySum << endl;
    return 0;
}