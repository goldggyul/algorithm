#include <iostream>
using namespace std;

/*
https://codeforces.com/contest/327/problem/A
*/

int n;
int arr[101];
int rev[101];
int maxRev[101];
int allSum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // 0�� �������� +1, 1�� �������� 0�� �ǹǷ� ������ 1��ŭ ����, ���� -1
        if (arr[i] == 1) {
            rev[i] = -1;
        } else { // 0
            rev[i] = 1;
        }
        // �� 1�� ����
        allSum += arr[i];
    }
    // �ϳ��� �� ������� �ϹǷ� maxRev[i]�� i���� ������(�����ϴ�) �ִ���
    maxRev[0] = rev[0];
    int maxSubsum = maxRev[0];
    for (int i = 1; i < n; i++) {
        maxRev[i] = max(rev[i], maxRev[i - 1] + rev[i]);
        maxSubsum = max(maxSubsum, maxRev[i]);
    }
    cout << maxSubsum + allSum << endl;

    return 0;
}