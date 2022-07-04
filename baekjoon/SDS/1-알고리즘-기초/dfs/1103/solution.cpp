// https://www.acmicpc.net/problem/1103
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int board[55][55];
int visited[55][55]; // 방문중 여부 & 내 다음 움직일 수 있는 경로
bool isCycle = false;
int n, m;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool isInRange(int x, int y) {
    return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

int dfs(int x, int y) {
    // 더 이상 탐색 불가거나 이미 싸이클 발견
    if (!isInRange(x, y) || board[x][y] == -1 || isCycle)
        return 0;
    if (visited[x][y] == 0) { // 이미 방문 중
        isCycle = true;
        return 0;
    } else if (visited[x][y] > 0) { // 이미 방문 끝남
        return visited[x][y];
    } else {
        visited[x][y] = 0; // 방문 중 (회색 칠하기)
        int result = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i] * board[x][y];
            int ny = y + dy[i] * board[x][y];
            result = max(result, dfs(nx, ny));
        }
        visited[x][y] = result + 1; // 방문 끝 (검은색 칠하기)
        return visited[x][y];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&visited[0][0], &visited[54][55], -1);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == 'H') board[i][j] = -1;
            else board[i][j] = input[j] - '0';
        }
    }
    
    dfs(0, 0);
    
    if (isCycle)
        cout << "-1" << endl;
    else
        cout << visited[0][0] << endl;
    
    return 0;
}