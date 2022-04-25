#include <iostream>
#include <vector>
using namespace std;

/*
https://www.acmicpc.net/problem/1967

다른 트리 문제와 마찬가지로
bottom up -> top down
child 기준 한번 구하고 -> parent 구하기
*/

int n;
struct Node {
    int p;
    int pDist;
    int maxChild;
    vector<int> adj;
    vector<int> dist;
    vector<int> distSum;
};
Node tree[10'001];

int dfs1(int s) {
    if (tree[s].adj.size() == 0) { // leaf
        return 0;
    }
    for (int i = 0; i < tree[s].adj.size(); i++) {
        tree[s].distSum[i] = dfs1(tree[s].adj[i]) + tree[s].dist[i];
        tree[s].maxChild = max(tree[s].maxChild, tree[s].distSum[i]);
    }
    return tree[s].maxChild;
}

int ans = 0;
void dfs2(int s, int pDist) {
    tree[s].pDist = pDist;
    ans = max(ans, tree[s].maxChild + tree[s].pDist);
    for (int i = 0; i < tree[s].adj.size(); i++) {
        int dist = 0;
        for (int j = 0; j < tree[s].adj.size(); j++) {
            if (i != j) {
                dist = max(dist, tree[s].distSum[j]);
            }
        }
        dfs2(tree[s].adj[i], dist + tree[s].dist[i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int p, c, dist;
        cin >> p >> c >> dist;
        tree[p].adj.push_back(c);
        tree[p].dist.push_back(dist);
        tree[p].distSum.push_back(-1);
        tree[c].p = p;
    }
    dfs1(1);
    dfs2(1, 0);
    cout << ans << endl;
}