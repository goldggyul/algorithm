// https://codeforces.com/problemset/problem/145/E
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int n; // 10^6
int m; // 3*10^5
string s;

struct Node {
    int four = 0;
    int seven = 0;
    int leftLongest = 0;
    int rightLongest = 0;
    bool isSwitched = false;
};
Node* t;

void build(int now, int left, int right) {
    if (left == right) { // leaf
        if (s[left - 1] == '4') {
            t[now].four = 1;
        } else {
            t[now].seven = 1;
        }
        t[now].leftLongest = 1;
        t[now].rightLongest = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(now * 2, left, mid);
    build(now * 2 + 1, mid + 1, right);
    t[now].four = t[now * 2].four + t[now * 2 + 1].four;
    t[now].seven = t[now * 2].seven + t[now * 2 + 1].seven;
    t[now].leftLongest = max(t[now * 2].leftLongest + t[now * 2 + 1].seven, t[now * 2].four + t[now * 2 + 1].leftLongest);
    t[now].rightLongest = max(t[now * 2].rightLongest + t[now * 2 + 1].four, t[now * 2].seven + t[now * 2 + 1].rightLongest);
}

int count() {
    return max(max(t[1].four, t[1].seven), t[1].leftLongest);
}

void change(int now, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        t[now].isSwitched = !t[now].isSwitched;
        swap(t[now].four, t[now].seven);
        swap(t[now].leftLongest, t[now].rightLongest);
        return;
    }
    int mid = (left + right) / 2;
    if (to <= mid) {
        change(now * 2, left, mid, from, to);
    } else if (mid + 1 <= from) {
        change(now * 2 + 1, mid + 1, right, from, to);
    } else {
        change(now * 2, left, mid, from, to);
        change(now * 2 + 1, mid + 1, right, from, to);
    }
    if (t[now].isSwitched) {
        t[now].four = t[now * 2].seven + t[now * 2 + 1].seven;
        t[now].seven = t[now * 2].four + t[now * 2 + 1].four;
        t[now].leftLongest = max(t[now * 2].rightLongest + t[now * 2 + 1].four, t[now * 2].seven + t[now * 2 + 1].rightLongest);
        t[now].rightLongest = max(t[now * 2].leftLongest + t[now * 2 + 1].seven, t[now * 2].four + t[now * 2 + 1].leftLongest);
    } else {
        t[now].four = t[now * 2].four + t[now * 2 + 1].four;
        t[now].seven = t[now * 2].seven + t[now * 2 + 1].seven;
        t[now].leftLongest = max(t[now * 2].leftLongest + t[now * 2 + 1].seven, t[now * 2].four + t[now * 2 + 1].leftLongest);
        t[now].rightLongest = max(t[now * 2].rightLongest + t[now * 2 + 1].four, t[now * 2].seven + t[now * 2 + 1].rightLongest);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s;

    int height = ceil(log2(n));
    t = new Node[1 << (height + 1)];
    build(1, 1, n);

    string op;
    for (int i = 0; i < m; i++) {
        cin >> op;
        if (op == "count") {
            cout << count() << endl;
        } else if (op == "switch") {
            int l, r;
            cin >> l >> r;
            change(1, 1, n, l, r);
        }
    }
    return 0;
}