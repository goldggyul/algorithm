// https://codeforces.com/problemset/problem/276/C
#include <iostream>
#include <algorithm>
using namespace std;

int n, q; // 2*10^5
int a[2 * 100'000 + 5];
int cnt[2 * 100'000 + 5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }

    sort(cnt + 1, cnt + 1 + n);
    sort(a + 1, a + 1 + n);

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        result += (long long)a[i] * cnt[i];
    }
    cout << result << endl;

    return 0;
}