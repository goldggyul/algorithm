// https://codeforces.com/problemset/problem/500/A
#include <iostream>
using namespace std;

int n; // 3*10^4
int t;
int a[30'005];

/*
n개의 cell -> 1~n 넘버링
i번째 포탈은 i와 i+ai와 연결
뒤로 갈 순 없다! -> directed... 즉, i-> i+ai는 되지만 거꾸로는 X
1에서 t에 갈 수 있을까요?
*/

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a[i];
    }
    int cur = 1;
    while (cur <= n - 1) {
        if (cur == t) break;
        cur = cur + a[cur];
    }
    if (cur == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}