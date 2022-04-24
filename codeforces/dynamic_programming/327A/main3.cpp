#include <iostream>
using namespace std;

/*
https://codeforces.com/contest/327/problem/A
*/

int n;
int arr[102];
int rev[102];
int preSum[102];
int allSum;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        // 0�� �������� +1, 1�� �������� 0�� �ǹǷ� ������ 1��ŭ ����, ���� -1
        if (arr[i] == 1) {
            rev[i] = -1;
        } else {
            rev[i] = 1;
        }
        preSum[i] = preSum[i - 1] + rev[i];
        // �� 1�� ����
        allSum += arr[i];
    }
    // �ִ� �� ã��
    int min = 0;
    int mx = preSum[1]; // �Ѱ��� �� ������� ��.
    for (int i = 1; i <= n; i++) {
        if (min > preSum[i]) {
            min = preSum[i];
        } else {
            mx = max(mx, preSum[i] - min);
        }
    }
    cout << mx + allSum << endl;

    return 0;
}