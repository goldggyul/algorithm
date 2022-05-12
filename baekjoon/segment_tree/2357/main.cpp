// https://www.acmicpc.net/problem/2357
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int n; // 10^5
int m; // 10^5

long long mn[4 * 100'005];
long long mx[4 * 100'005];
long long a[100'005];

void build(int now, int l, int r) {
    if (l == r) {
        mn[now] = a[l];
        mx[now] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(now * 2, l, mid);
    build(now * 2 + 1, mid + 1, r);
    mn[now] = min(mn[now * 2], mn[now * 2 + 1]);
    mx[now] = max(mx[now * 2], mx[now * 2 + 1]);
}

pair<long long, long long> findMinMax(int now, int l, int r, int from, int to) {
    if (from <= l && r <= to) {
        return pair<long long, long long>(mn[now], mx[now]);
    }
    int mid = (l + r) / 2;
    if (to <= mid) {
        return findMinMax(now * 2, l, mid, from, to);
    } else if (mid + 1 <= from) {
        return findMinMax(now * 2 + 1, mid + 1, r, from, to);
    }
    pair<long long, long long> result1 = findMinMax(now * 2, l, mid, from, to);
    pair<long long, long long>  result2 = findMinMax(now * 2 + 1, mid + 1, r, from, to);
    result1.first = min(result1.first, result2.first);
    result1.second = max(result1.second, result2.second);
    return result1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        pair<long long, long long> p = findMinMax(1, 1, n, a, b);
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}