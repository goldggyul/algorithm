#include <iostream>
using namespace std;

// * https://codeforces.com/problemset/problem/448/C

int n;
int input[5001];

int paintFence(int arr[], int s) {
    int minHeight = 1'000'000'001;
    for (int i = 0; i < s; i++) {
        minHeight = min(arr[i], minHeight);
    }
    // 나머지 부분에 대해 재귀적으로 계산하기 위해, 칠한 부분 뺌
    for (int i = 0; i < s; i++) {
        arr[i] -= minHeight;
    }
    int result = minHeight;

    // 이제 돌면서 남은 부분 탐색
    int p = 0;
    while (p < s) {
        while (p < s && arr[p] == 0) p++;
        // * 없을 경우!
        if (p == s) break;
        int q = p;
        while (q + 1 < s && arr[q + 1] != 0)q++;
        result += paintFence(arr + p, q - p + 1);
    }
    // 근데 가로로 칠하는 것보다 그냥 세로로 칠하는 게 더 적은 경우일 수 있다.
    // 따라서 비교해서 더 작은 걸로
    return min(result, s);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << paintFence(input, n) << endl;
    return 0;
}