// https://codeforces.com/problemset/problem/449/B
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n; // 10^5
int m; // 3*10^5
int k; // 10^5

// 그래프
vector<pair<int, int>> graph[100'005]; // node/edge 번호 순서
int weight[400'005]; // w <= 10^9, 일반 루트 + 기찻길 루트 -> 400'000개
bool visited[100'005]; // 노드 방문했는지

int allSum = 0;

struct pkt {
    long long weightSum = 0;
    bool isTrainRoute = false;
    int node = 0; // 어떤 노드로 들어가는 패킷인지
    bool operator< (const pkt& o) const { // priority_queue는 내림차순이므로 '작다면' 밀려난다. 언제 밀려날지 생각하면 됨
        if (weightSum == o.weightSum) {
            return isTrainRoute; // 기찻길이면 제외 (priority_queue는 내림차순이므로 여기선 거꾸로..)
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
        if (cur.isTrainRoute) allSum++;
        for (int i = 0; i < graph[cur.node].size(); i++) {
            if (visited[graph[cur.node][i].first]) continue; // 없어도 문제는 없지만, 방문한건 그냥 queue에 넣지 않음
            pkt next;
            next.node = graph[cur.node][i].first;
            next.weightSum = cur.weightSum + weight[graph[cur.node][i].second];
            next.isTrainRoute = (graph[cur.node][i].second > m) ? true : false;
            pq.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        cin >> weight[i];
        graph[u].push_back(make_pair(v, i));
        graph[v].push_back(make_pair(u, i));
    }
    for (int i = 1 + m; i <= k + m; i++) {
        int s, y; // city, length
        cin >> s >> weight[i];
        // 기찻길은 모두 capital(1)에서 각 도시로 감
        // 따라서 다익스트라 시작할 때 capital에서 출발하므로, 모든 route by train이 queue에 들어간다.
        // 따라서 위에 일반 도시들처럼 굳이 거꾸로 넣어줄 필요는 없다
        graph[1].push_back(make_pair(s, i));
    }

    dijkstra(1);

    cout << k - allSum << endl;
    return 0;
}