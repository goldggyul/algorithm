// https://codeforces.com/problemset/problem/52/C?f0a28=1
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    long long min;
    long long upd;
};
Node tree[525'000];

int n;
int arr[200'001];
int m;

int build(int node, int left, int right) {
    if (left == right) { // 리프일 때
        tree[node].min = arr[left];
    } else {
        int mid = (left + right) / 2;
        int leftMin = build(node * 2, left, mid);
        int rightMin = build(node * 2 + 1, mid + 1, right);
        tree[node].min = min(leftMin, rightMin);
    }
    return tree[node].min;
}

void update(int node, int leftIdx, int rightIdx, int left, int right, int v) {
    if (leftIdx >= left && rightIdx <= right) {
        tree[node].upd += v;
        return;
    }
    int mid = (leftIdx + rightIdx) / 2;
    if (right <= mid) {
        update(node * 2, leftIdx, mid, left, right, v);
    } else if (mid < left) {
        update(node * 2 + 1, mid + 1, rightIdx, left, right, v);
    } else {
        update(node * 2, leftIdx, mid, left, right, v);
        update(node * 2 + 1, mid + 1, rightIdx, left, right, v);
    }
    tree[node].min = min(tree[node * 2].min + tree[node * 2].upd, tree[node * 2 + 1].min + tree[node * 2 + 1].upd);
}

long long query(int node, int leftIdx, int rightIdx, int left, int right) {
    if (leftIdx >= left && rightIdx <= right) {
        return tree[node].min + tree[node].upd;
    }
    int mid = (leftIdx + rightIdx) / 2;
    if (right <= mid) {
        return query(node * 2, leftIdx, mid, left, right) + tree[node].upd;
    } else if (mid < left) {
        return query(node * 2 + 1, mid + 1, rightIdx, left, right) + tree[node].upd;
    } else {
        int leftMin = query(node * 2, leftIdx, mid, left, right);
        int rightMin = query(node * 2 + 1, mid + 1, rightIdx, left, right);
        return min(leftMin, rightMin) + tree[node].upd;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    build(1, 1, n);

    cin >> m;
    cin.ignore();
    for (int i = 0; i < m; i++) {
        string input;
        getline(cin, input);
        stringstream ss(input);

        int lf, rg, v;
        ss >> lf >> rg;
        lf++;
        rg++;

        if (ss >> v) {
            if (lf <= rg) {
                update(1, 1, n, lf, rg, v);
            } else {
                update(1, 1, n, lf, n, v);
                update(1, 1, n, 1, rg, v);
            }
        } else { // query
            if (lf <= rg) {
                cout << query(1, 1, n, lf, rg) << endl;
            } else {
                cout << min(query(1, 1, n, lf, n), query(1, 1, n, 1, rg)) << endl;
            }
        }
    }

}