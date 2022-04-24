#include <iostream>
using namespace std;

// * https://codeforces.com/problemset/problem/1285/B
// * Prefix sum
// ! int -> long long: Watch out of range

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[100'001];
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        long long p[100'001];
        p[0] = 0;
        int minIdx = 0;
        long long max = 0;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] + arr[i];
        }

        bool IsGreater = true;
        for (int i = 1; i <= n; i++) {
            if (p[i] - p[minIdx] >= p[n]) {
                // 단 전체 선택하는 경우는 제외
                if (i == n && minIdx == 0) break;
                IsGreater = false;
            }
            if (p[minIdx] >= p[i]) {
                minIdx = i;
            }
        }
        // 'strictly' greater
        if (IsGreater) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}