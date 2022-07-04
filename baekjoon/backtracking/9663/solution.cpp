// https://www.acmicpc.net/problem/9663
#include <iostream>
using namespace std;

/*
이미 풀어본거지만..

퀸은 가로,세로,대각선이니까
만약 백트랙킹을 안하면 15^15
따라서 놔둘 수 있는 곳인지 체크해야함

이 때 대각선 인덱스 조심
 /|/|/|///   <- 여기가 인덱스
 /|/|/|//
 /|/|/|/
3*3의 보드가 있다고 하면, 저렇게 가상의 선이 있다고 생각하고,
맨 위에 인덱스가 대각선 인덱스가 된다고 생각하고 인덱스 넘버링을 했다.

그래서 위 그림처럼 upDiagonal인 경우 row만큼 오른쪽으로 열 번호를 밀었고,
down인경우 row만큼 왼쪽으로 번호를 밀었다.
*/

bool colVisited[20];
bool upDiagVisited[40];
bool downDiagVisited[40];

int n;
int ans = 0;
void dfs(int row) {
    if (row == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        int r = row;
        int upDiag = row + i;
        int downDiag = i - row;
        if (!colVisited[i] && !upDiagVisited[upDiag] && !downDiagVisited[downDiag]) {
            colVisited[i] = true;
            upDiagVisited[upDiag] = true;
            downDiagVisited[downDiag] = true;
            dfs(row + 1);
            colVisited[i] = false;
            upDiagVisited[upDiag] = false;
            downDiagVisited[downDiag] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans << endl;
    return 0;
}