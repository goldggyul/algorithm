// https://www.acmicpc.net/problem/2573
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

/*
굳이 덩어리 다 안세줘도
1개 초과기만 한다면 분리됐으므로 정답
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sea[flag][i][j] > 0) {
                q.push({ i,j });
                break;
            }
        }
        if (!q.empty()) break;
    }
    if (q.empty()) {
        ans = 0;
        return true;
    }

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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (sea[flag][i][j] > 0 && !visited[i][j]) {
                return true;
            }
        }
    }
    return false;
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