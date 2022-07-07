// https://www.acmicpc.net/problem/2042
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int n, m, k;
ll arr[1000005];
ll* tree;

void build(int now, int left, int right) {
    if (left == right) { // leaf
        tree[now] = arr[left];
        return;
    }
    int mid = left + (right - left) / 2;
    build(now * 2, left, mid);
    build(now * 2 + 1, mid + 1, right);
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

void update(int now, int left, int right, int target, ll value) {
    if (left == right && left == target) {
        tree[now] = value;
        return;
    }
    int mid = left + (right - left) / 2;
    if (target <= mid) {
        update(now * 2, left, mid, target, value);
    } else if (mid + 1 <= target) {
        update(now * 2 + 1, mid + 1, right, target, value);
    } else {
        update(now * 2, left, mid, target, value);
        update(now * 2 + 1, mid + 1, right, target, value);
    }
    tree[now] = tree[now * 2] + tree[now * 2 + 1];
}

ll query(int now, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return tree[now];
    }
    int mid = left + (right - left) / 2;
    if (to <= mid) {
        return query(now * 2, left, mid, from, to);
    } else if (mid + 1 <= from) {
        return query(now * 2 + 1, mid + 1, right, from, to);
    } else {
        return query(now * 2, left, mid, from, to) +
            query(now * 2 + 1, mid + 1, right, from, to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int height = ceil(log2(n)) + 1;
    tree = new ll[1 << height];
    build(1, 1, n);

    int q = m + k;
    while (q--) {
        int op;
        ll a, b;
        cin >> op >> a >> b;
        if (op == 1) { // a를 b로 바꾸기
            update(1, 1, n, a, b);
        } else if (op == 2) { // a부터 b까지 합
            cout << query(1, 1, n, a, b) << '\n';
        }
    }
    return 0;
}