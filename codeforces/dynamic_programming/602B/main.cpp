#include <iostream>
#define START 0
#define CON 1
using namespace std;

/*
https://codeforces.com/problemset/problem/602/B
*/
int n;
int arr[100'001];

int m, M, mi, Mi, length;
int ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    m = M = arr[0], mi = Mi = 0, ans = length = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < m) {
            if (m == M) {
                mi = i;
                m = arr[i];
                length++;
            } else { // 다시 시작
                ans = max(ans, length);
                length = i - Mi;
                Mi = mi;
                M = m;
                mi = i;
                m = arr[i];
            }
        } else if (arr[i] > M) {
            if (m == M) {
                Mi = i;
                M = arr[i];
                length++;
            } else { // 다시 시작
                ans = max(ans, length);
                length = i - mi;
                mi = Mi;
                m = M;
                Mi = i;
                M = arr[i];
            }
        } else if (arr[i] == m || arr[i] == M) {
            length++;
            if (arr[i] == m) {
                mi = i;
            }
            if (arr[i] == M) {
                Mi = i;
            }
        }
    }
    cout << max(ans, length) << endl;
    return 0;
}