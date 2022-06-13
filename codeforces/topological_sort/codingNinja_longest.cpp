// https://www.codingninjas.com/codestudio/problems/longest-path-in-directed-graph_1172157
vector<pair<int, int>> edgeTo[10005]; // 노드, 거리 순
vector<int> maxDist;
bool visited[10005];

// 내 왼쪽 끝까지 들어간다
void dfs(int s) {
    visited[s] = true;
    for (int i = 0; i < edgeTo[s].size(); i++) {
        int prior = edgeTo[s][i].first;
        int length = edgeTo[s][i].second;
        if (!visited[prior])
            dfs(prior);
        if (maxDist[prior] != -1)
            maxDist[s] = max(maxDist[s], maxDist[prior] + length);
    }
}

vector<int> findMaxDistances(int n, int src, vector<vector<int>>& edges) {
    fill(visited, visited + n, false);
    maxDist.clear();
    for (int i = 0; i < n; i++) {
        maxDist.push_back(-1);
        edgeTo[i].clear();
    }

    for (int i = 0; i < edges.size(); i++) {
        // edgeTo[i]: i로 들어오는 모든 엣지의 시작 노드/거리를 기록한다
        edgeTo[edges[i][1]].push_back(make_pair(edges[i][0], edges[i][2]));
    }
    maxDist[src] = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i);
    return maxDist;
}