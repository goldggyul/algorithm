// https://www.acmicpc.net/problem/2805
#include <iostream>
#include <algorithm>
using namespace std;

/*
처음엔 모든 높이별로 잘라보면서 upper_bound를 이용하는 줄 알고 접근했다가 시간 초과가 났다.

N의 크기를 보면 N^2이 안되기때문에 탐색 시에 이분 탐색을 이용해서 시간을 줄여보자.
이분탐색으로 중간 높이로 잘라보면서 합을 구한 다음,
M보다 같거나 크면 더 높은 높이로도 답이 되는 지 확인해보고,
작으면 더 낮은 높이로 잘라보면서 최대한 높은 높이를 찾는다.
*/

int n, m;
int arr[1'000'005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int mxHeight = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    mxHeight = arr[n - 1];
    int lo = 0;
    int hi = mxHeight;
    int ans = 0;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (mid < arr[i]) sum += arr[i] - mid;
        }
        if (sum >= m) {
            lo = mid + 1;
            if (ans < mid) ans = mid;
        } else { // 더 낮게 도전
            hi = mid;
        }
    }
    cout << ans << endl;
    return 0;
}