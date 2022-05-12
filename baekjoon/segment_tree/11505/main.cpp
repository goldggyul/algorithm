// https://www.acmicpc.net/problem/11505
// 나눌 때는 항상 0으로 나누는 지 생각하기..
#include <iostream>
#include <cmath>
#define DIVISOR 1'000'000'007
using namespace std;

int n; // 10^6
int m; // 10^4
int k; // 10^4
int a[1'000'005];
long long t[4 * 1'000'005];

int build(int now, int l, int r) {
    if (l == r) {
        t[now] = a[l];
        return t[now];
    }
    int mid = (l + r) / 2;
    t[now] = 1;
    t[now] = (t[now] * build(now * 2, l, mid)) % DIVISOR;
    t[now] = (t[now] * build(now * 2 + 1, mid + 1, r)) % DIVISOR;
    return t[now];
}

void change(int now, int l, int r, int target, int value) {
    if (l == r && l == target) {
        t[now] = value;
        return;
    }
    int mid = (l + r) / 2;
    if (target <= mid) {
        change(now * 2, l, mid, target, value);
    } else if (mid + 1 <= target) {
        change(now * 2 + 1, mid + 1, r, target, value);
    } else {
        change(now * 2, l, mid, target, value);
        change(now * 2 + 1, mid + 1, r, target, value);
    }
    t[now] = (t[now * 2] * t[now * 2 + 1]) % DIVISOR;
}

int multiply(int now, int l, int r, int from, int to) {
    if (from <= l && r <= to) {
        return t[now];
    }
    int mid = (l + r) / 2;
    if (to <= mid) {
        return multiply(now * 2, l, mid, from, to);
    } else if (mid + 1 <= from) {
        return multiply(now * 2 + 1, mid + 1, r, from, to);
    }
    long long product = multiply(now * 2, l, mid, from, to);
    product = (product * multiply(now * 2 + 1, mid + 1, r, from, to)) % DIVISOR;
    return product;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    int op, l, r;
    for (int i = 0; i < m + k; i++) {
        cin >> op >> l >> r;
        if (op == 1) {
            change(1, 1, n, l, r);
        } else {
            cout << multiply(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}