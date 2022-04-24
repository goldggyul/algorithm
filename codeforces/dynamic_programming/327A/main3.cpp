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
        // 0은 뒤집으면 +1, 1은 뒤집으면 0이 되므로 기존의 1만큼 감소, 따라서 -1
        if (arr[i] == 1) {
            rev[i] = -1;
        } else {
            rev[i] = 1;
        }
        preSum[i] = preSum[i - 1] + rev[i];
        // 총 1의 개수
        allSum += arr[i];
    }
    // 최대 합 찾기
    int min = 0;
    int mx = preSum[1]; // 한개는 꼭 뒤집어야 함.
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