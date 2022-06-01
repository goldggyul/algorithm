// https://www.acmicpc.net/problem/16975
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N, M;
int* A;
long long* tree;

void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = A[left];
        return;
    }
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);
}

void update(int now, int left, int right, int from, int to, int upd) {
    if (from <= left && right <= to) {
        tree[now] += upd;
        return;
    }
    int mid = (left + right) / 2;
    if (to <= mid) {
        update(now * 2, left, mid, from, to, upd);
    } else if (mid + 1 <= from) {
        update(now * 2 + 1, mid + 1, right, from, to, upd);
    } else {
        update(now * 2, left, mid, from, to, upd);
        update(now * 2 + 1, mid + 1, right, from, to, upd);
    }
}

long long query(int now, int left, int right, int target) {
    if (left == right && left == target) {
        return tree[now];
    }
    int mid = (left + right) / 2;
    if (target <= mid) {
        return query(now * 2, left, mid, target) + tree[now];
    } else if (mid + 1 <= target) {
        return query(now * 2 + 1, mid + 1, right, target) + tree[now];
    } else {
        long long leftVal = query(now * 2, left, mid, target);
        long long rightVal = query(now * 2 + 1, mid + 1, right, target);
        return leftVal + rightVal + tree[now];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    A = new int[N + 5];
    int height = ceil(log2(N));
    tree = new long long[1 << (height + 1)];

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    build(1, 1, N);

    cin >> M;
    while (M--) {
        int q;
        cin >> q;
        if (q == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            update(1, 1, N, i, j, k);
        } else if (q == 2) {
            int x;
            cin >> x;
            cout << query(1, 1, N, x) << '\n';
        }
    }
}