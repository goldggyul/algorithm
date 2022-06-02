// https://www.youtube.com/watch?v=AVXKYCH7Myo
#include <iostream>
#include <vector>
using namespace std;

int n; // 10^2
int x[105];
int y[105];
bool visited[105];
vector<int> adj[105];

void search(int now) {
    visited[now] = true;
    for (int i = 0; i < adj[now].size(); i++) {
        if (!visited[adj[now][i]])
            search(adj[now][i]);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    // 인접 행렬 만들기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // i == j 인건 어차피 dfs에서 무시되므로 상관없음
            if (x[i] == x[j] || y[i] == y[j]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int connectedCnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            search(i);
            connectedCnt++;
        }
    }
    cout << connectedCnt - 1 << endl;
    return 0;
}