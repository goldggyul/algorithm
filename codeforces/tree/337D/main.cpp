#include <iostream>
#include <vector>
using namespace std;

int n, m, d;
struct Node {
    int p;
    bool isDamaged;
    int childCnt;
    int pDist;
    int maxChild = -1;
    vector<int> adj;
    vector<int> sum;
    vector<int> prefix;
    vector<int> suffix;
};
Node tree[100'001];

int dfs1(int s, int p) {
    Node& cur = tree[s];
    cur.p = p;
    for (int i = 0; i < cur.adj.size(); i++) {
        if (cur.p != cur.adj[i]) {
            int temp = dfs1(cur.adj[i], s);
            if (temp == -1) {
                cur.sum[i] = -1;
            } else {
                cur.sum[i] = temp + 1;
                cur.maxChild = max(cur.maxChild, cur.sum[i]);
            }
            cur.childCnt++;
        }
    }
    if (cur.childCnt == 0) {
        if (cur.isDamaged) {
            cur.maxChild = 0;
        } else {
            cur.maxChild = -1;
        }
    } else if (cur.maxChild == -1 && cur.isDamaged) {
        cur.maxChild = 0;
    }
    return cur.maxChild;
}

void dfs2(int s, int pDist) {
    Node& cur = tree[s];
    if (pDist == -1 && cur.isDamaged) {
        cur.pDist = 0;
    } else {
        cur.pDist = pDist;
    }
    // pre & suffix
    int size = cur.adj.size();
    for (int i = 0; i < size; i++) {
        int prePrefix = -1, preSuffix = -1;
        if (i != 0) {
            prePrefix = cur.prefix[i - 1];
            preSuffix = cur.suffix[size - i];
        }
        cur.prefix[i] = max(prePrefix, cur.sum[i]);
        cur.suffix[size - 1 - i] = max(preSuffix, cur.sum[size - 1 - i]);
    }
    for (int i = 0; i < cur.adj.size(); i++) {
        if (cur.adj[i] != cur.p) {
            int mx = cur.pDist;
            if (i > 0) {
                mx = max(mx, cur.prefix[i - 1]);
            }
            if (i < cur.adj.size() - 1) {
                mx = max(mx, cur.suffix[i + 1]);
            }
            if (mx != -1) {
                mx += 1;
            }
            dfs2(cur.adj[i], mx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> d;
    for (int i = 0; i < m; i++) {
        int p;
        cin >> p;
        tree[p].isDamaged = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].adj.push_back(v);
        tree[u].sum.push_back(-1);
        tree[u].prefix.push_back(-1);
        tree[u].suffix.push_back(-1);
        tree[v].adj.push_back(u);
        tree[v].sum.push_back(-1);
        tree[v].prefix.push_back(-1);
        tree[v].suffix.push_back(-1);
    }
    dfs1(1, 0);
    dfs2(1, -1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int mx = max(tree[i].maxChild, tree[i].pDist);
        if (mx != -1 && mx <= d) {
            cnt++;
        }
    }
    std::cout << cnt << endl;
    return 0;
}