#include <iostream>
#include <vector>
using namespace std;

/*
https://codeforces.com/problemset/problem/839/C
*/

int n;
struct Node {
    int pt;
    int childCnt;
    vector<int> adj;
};
Node tree[100'001];

void setParent(int s, int pt) {
    tree[s].pt = pt;
    for (int i = 0; i < tree[s].adj.size(); i++) {
        int node = tree[s].adj[i];
        if (node != pt) {
            setParent(node, s);
            tree[s].childCnt++;
        }
    }
}

double dfs(int s) {
    if (tree[s].childCnt == 0) return 0;
    double sum = 0;
    for (int i = 0; i < tree[s].adj.size(); i++) {
        int node = tree[s].adj[i];
        if (tree[s].pt != node) {
            sum += dfs(node) + 1;
        }
    }
    return sum / tree[s].childCnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].adj.push_back(v);
        tree[v].adj.push_back(u);
    }
    setParent(1, 0);

    cout << fixed; // 소숫점 이하
    cout.precision(6); // 6자리까지 나타내기
    cout << dfs(1) << endl;

    return 0;
}