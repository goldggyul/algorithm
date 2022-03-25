#include <iostream>
using namespace std;

// * https://codeforces.com/problemset/problem/448/C

int n;
int arr[5001];

int paintFence(int start, int end) {
    if (start == end) return 0;
    // 최솟값 찾기
    int minHeight = 1'000'000'001;
    for (int i = start; i < end; i++) {
        minHeight = min(arr[i], minHeight);
    }
    // 나머지 부분에 대해 재귀적으로 계산하기 위해, 칠한 부분 뺌
    for (int i = start; i < end; i++) {
        arr[i] -= minHeight;
    }
    // 이제 돌면서 남은 부분 탐색
    int s = start - 1;
    int result = 0;
    for (int i = start; i < end; i++) {
        if (arr[i] == 0) {
            result += paintFence(s + 1, i);
            s = i;
        }
    }
    // 마지막도 확인
    result += paintFence(s + 1, end);
    // 근데 가로로 칠하는 것보다 그냥 세로로 칠하는 게 더 적은 경우일 수 있다.
    // 따라서 비교해서 더 작은 걸로
    result = min(end - start, result + minHeight);
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << paintFence(0, n) << endl;
    return 0;
}