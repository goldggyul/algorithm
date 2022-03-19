#include <iostream>
using namespace std;

/*
* Greedy!
* https://codeforces.com/problemset/problem/158/B
*/
int main() {
    int n;
    cin >> n;

    // 1,2,3,4명 그룹의 수 세기
    int g[5] = { /* unused */0, /* 1명인 그룹 수.. */0,0,0,0 };
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        g[temp]++;
    }

    // #1
    /* int t = 0; // 최종 택시 수
    t += g[4]; // 일단 4명 먼저 태우기
    t += g[2] / 2; // 2명 그룹끼리 탈 수 있으면 먼저 태우기
    g[2] %= 2; // 태우고 남은 2명 그룹
    // 이제 1명 그룹을 3명, 2명으로 태우면 된다
    int leftSeat = 2 * g[2] + g[3];
    if (leftSeat >= g[1]) {
        t += g[2] + g[3];
    } else { // 1명 그룹이 다 나눠서 못타므로 얘네끼리 또 태워줌
        g[1] -= leftSeat;
        t += g[2] + g[3];
        t += g[1] / 4;
        if (g[1] % 4 != 0) {
            t += 1;
        }
    }
    cout << t << endl; */

    // #2
    int t = 0;
    t += g[4]; // 4명 먼저 태우기
    g[1] -= min(g[3], g[1]); // 3명, 1명 먼저 태우기
    t += g[3];
    t += g[2] / 2; // 2명, 2명 먼저 태우기
    g[2] %= 2;
    g[1] -= min(2 * g[2], g[1]); // 2명 택시 남은 자리에 1명 채워넣기
    t += g[2];
    t += g[1] / 4; // 나머지 1명 태우기
    if (g[1] % 4 != 0) t++;
    cout << t << endl;

    return 0;
}