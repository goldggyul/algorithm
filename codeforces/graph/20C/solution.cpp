// https://codeforces.com/problemset/problem/20/C
#include <iostream>
#include <queue>
using namespace std;

int n; // 10^5
int m; // 10^6
vector<pair<int, int>> adj[100'005]; // 정점, 거리 순
bool visited[100'005];
long long dist[100'005];
int preNode[100'005];

struct pkt {
    long long d;
    int node;
    int pre;
    bool operator< (const pkt& o) const {
        return d > o.d;
    }
};

void dijkstra(int s) {
    priority_queue<pkt> q;
    q.push({ 0, s, 0 });
    while (!q.empty()) {
        pkt p = q.top(); q.pop();
        if (visited[p.node]) continue;
        visited[p.node] = true;
        dist[p.node] = p.d;
        preNode[p.node] = p.pre;
        for (int i = 0; i < adj[p.node].size(); i++) {
            q.push({ dist[p.node] + adj[p.node][i].second,
            adj[p.node][i].first, p.node });
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }
    fill(dist + 1, dist + 1 + n, -1);
    dijkstra(1);
    if (dist[n] == -1) {
        cout << "-1" << endl;
        return 0;
    }
    int cur = n;
    vector<int> order;
    while (cur != 0) {
        order.push_back(cur);
        cur = preNode[cur];
    }
    for (int i = order.size() - 1; i >= 0; i--)
        cout << order[i] << " ";
    cout << endl;
    return 0;
}