// https://www.acmicpc.net/problem/2573
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

/*
정말 많이 틀렸는데..
우선 처음에 매번 녹여보고 + 탐색해보면 시간초과 날 것 같았는데 시간초과는 안났다.

bfs를 계속 돌리면서 방문안한 노드가 남아있다면 덩어리 추가.. 하는 식으로 카운트했다.
그리고 녹을 때 기존 맵에서 녹인다면 다음 빙하가 녹을 때 영향을 줄 것이다.
따라서 한꺼번에 녹을 수 있도록 맵(sea)를 하나 더 둬서 토글하면서 구현했다.

다만 중간에 틀렸던 이유 중에 하나가 [0]번 맵에만 채우고 [1]번 맵에는 입력을 안채워서 틀렸었다.
+ 다른 이유들은
    덩어리 셀 때 하나 세고 break해버렸던것;

*/

int n, m;
int sea[2][305][305]; // toggle

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int ans = 0;
int flag = 0;
bool visited[305][305];

bool isSeparated() {
    fill(&visited[0][0], &visited[304][305], false);

    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sea[flag][i][j] > 0 && !visited[i][j]) {
                q.push({ i,j });
                while (!q.empty()) {
                    pair<int, int> cur = q.front(); q.pop();
                    int x = cur.first;
                    int y = cur.second;
                    if (visited[x][y] || sea[flag][x][y] <= 0) continue;
                    visited[x][y] = true;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        q.push({ nx,ny });
                    }
                }
                cnt++;
            }
        }
    }
    if (cnt == 0) {
        ans = 0;
        return true;
    } else if (cnt == 1) {
        return false;
    } else {
        return true;
    }
}


int main() {
    cin >> n >> m;
    fill(&sea[0][0][0], &sea[1][304][305], -1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> sea[flag][i][j];
            sea[1 - flag][i][j] = sea[flag][i][j];
        }
    }

    while (!isSeparated()) {
        ans++;
        int next = 1 - flag;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (sea[flag][i][j] > 0) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        if (sea[flag][i + dx[k]][j + dy[k]] == 0) {
                            cnt++;
                        }
                    }
                    if (cnt > 0)
                        sea[next][i][j] = sea[flag][i][j] - cnt;
                    if (sea[next][i][j] < 0) sea[next][i][j] = 0;
                } else {
                    sea[next][i][j] = sea[flag][i][j];
                }
            }
        }
        flag = next;
    }
    cout << ans << endl;
    return 0;
}