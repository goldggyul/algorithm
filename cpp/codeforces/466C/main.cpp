#include <iostream>
using namespace std;

// * https://codeforces.com/problemset/problem/466/C
// * O(n^2) 불가능 -> n이 50'000
// * O(n)... Prefix sum 활용

int main() {
    int n;
    int arr[500001];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    long long preSum[500001];
    preSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + arr[i];
    }

    long long result = 0;
    long long sum = preSum[n];
    if (sum % 3 == 0) {
        long long oneThirdSum = preSum[n] / 3;
        int oneThirdCnt = 0;
        // 전체합의 2/3 지점 찾기 -> 그 전까지 1/3의 개수
        for (int i = 1; i <= n - 1; i++) {
            // ! 1/3과 2/3 개수를 세는 순서를 바꾸면 '0'이 되는 때 틀릴 수 있음
            // ! 극단적인 경우 잘 따지기
            if (preSum[i] == oneThirdSum * 2) {
                result += oneThirdCnt;
            }
            if (preSum[i] == oneThirdSum) oneThirdCnt++;
        }
    }
    cout << result << endl;

    return 0;
}