// https://codeforces.com/problemset/problem/545/E
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n; // 3*10^5
int m; // 3*10^5

// 그래프
vector<pair<int, int>> graph[300'005]; // node/edge 번호 순서
// output에 total weight 합 있으므로 기록 필요
int weight[300'005]; // w <= 10^9
bool isEdgeInTree[300'005]; // weight가 트리에 있는지
bool visited[300'005]; // 노드 방문했는지

struct pkt {
    long long weightSum = 0;
    int priorWeight = 0;
    int node = 0; // 어떤 노드로 들어가는 패킷인지
    int edgeNum = 0;
    bool operator< (const pkt& o) const {
        if (weightSum == o.weightSum) {
            return priorWeight > o.priorWeight;
        }
        return weightSum > o.weightSum;
    }

};

priority_queue<pkt> pq;

void dijkstra(int source) {
    pkt p;
    p.node = source;
    pq.push(p);
    while (!pq.empty()) {
        pkt cur = pq.top(); pq.pop();
        if (visited[cur.node]) continue;
        visited[cur.node] = true;
        isEdgeInTree[cur.edgeNum] = true;
        for (int i = 0; i < graph[cur.node].size(); i++) {
            if (visited[graph[cur.node][i].first]) continue;
            pkt next;
            next.node = graph[cur.node][i].first;
            next.weightSum = cur.weightSum + weight[graph[cur.node][i].second];
            next.priorWeight = weight[graph[cur.node][i].second];
            next.edgeNum = graph[cur.node][i].second;
            pq.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        cin >> weight[i];
        graph[u].push_back(make_pair(v, i));
        graph[v].push_back(make_pair(u, i));
    }
    int source;
    cin >> source;

    dijkstra(source);

    // 결과 출력
    long long allSum = 0;
    for (int i = 1; i <= m; i++) {
        if (isEdgeInTree[i])
            allSum += weight[i];
    }
    cout << allSum << endl;
    for (int i = 1; i <= m; i++) { // 트리에 포함되어 있다면 순서 상관 없음
        if (isEdgeInTree[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}