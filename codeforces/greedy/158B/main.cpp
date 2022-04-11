#include <iostream>
using namespace std;

/*
* Greedy!
* https://codeforces.com/problemset/problem/158/B
*/
int main() {
    int n;
    cin >> n;

    // 1,2,3,4�� �׷��� �� ����
    int g[5] = { /* unused */0, /* 1���� �׷� ��.. */0,0,0,0 };
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        g[temp]++;
    }

    // #1
    /* int t = 0; // ���� �ý� ��
    t += g[4]; // �ϴ� 4�� ���� �¿��
    t += g[2] / 2; // 2�� �׷쳢�� Ż �� ������ ���� �¿��
    g[2] %= 2; // �¿�� ���� 2�� �׷�
    // ���� 1�� �׷��� 3��, 2������ �¿�� �ȴ�
    int leftSeat = 2 * g[2] + g[3];
    if (leftSeat >= g[1]) {
        t += g[2] + g[3];
    } else { // 1�� �׷��� �� ������ ��Ÿ�Ƿ� ��׳��� �� �¿���
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
    t += g[4]; // 4�� ���� �¿��
    g[1] -= min(g[3], g[1]); // 3��, 1�� ���� �¿��
    t += g[3];
    t += g[2] / 2; // 2��, 2�� ���� �¿��
    g[2] %= 2;
    g[1] -= min(2 * g[2], g[1]); // 2�� �ý� ���� �ڸ��� 1�� ä���ֱ�
    t += g[2];
    t += g[1] / 4; // ������ 1�� �¿��
    if (g[1] % 4 != 0) t++;
    cout << t << endl;

    return 0;
}