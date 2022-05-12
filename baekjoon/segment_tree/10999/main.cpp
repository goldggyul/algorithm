// https://www.acmicpc.net/problem/10999
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n; // 10^6
int m; // 10^4
int k; // 10^4

long long a[1'000'005];

struct Node {
    long long sum = 0; // 나 포함 내 아래 합
    long long upd = 0; // 나 포함 내 아래 전체에 업데이트 되어야 하는 값
};

Node* t;

long long build(int now, int left, int right) {
    if (left == right) { // leaf node
        t[now].sum = a[left];
    } else {
        int mid = (left + right) / 2;
        t[now].sum += build(now * 2, left, mid);
        t[now].sum += build(now * 2+1, mid + 1, right);
    }
    return t[now].sum;
}

long long update(int now, int left, int right, int from, int to, long long value) {
    if (from <= left && right <= to) {
        t[now].upd += value;
        return value * (right-left+1);
    }
    int mid = (left + right) / 2;
    long long upd=0;
    if (to <= mid) {
        upd+=update(now * 2, left, mid, from, to, value);
    } else if (mid+1<=from) {
        upd+=update(now * 2 + 1, mid + 1, right, from, to, value);
    } else {
        upd+=update(now * 2, left, mid, from, to, value);
        upd+=update(now * 2 + 1, mid + 1, right, from, to, value);
    }
    t[now].sum += upd;
    return upd;
}

long long sum(int now, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        return t[now].sum + t[now].upd * (right - left + 1);
    }
    int mid = (left + right) / 2;
    long long result;
    if (to <= mid) {
        result = sum(now * 2, left, mid, from, to);
    } else if (mid + 1 <= from) {
        result = sum(now * 2 + 1, mid + 1, right, from, to);
    } else {
        result = sum(now * 2, left, mid, from, to);
        result += sum(now * 2 + 1, mid + 1, right, from, to);
    }
    // 내 left~right 중 from~to에 속하는 개수만큼 upd를 곱해줘야함
    int scope = min(right, to) - max(left, from) +1;
    return result + t[now].upd * scope;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int height = ceil(log2(n)); // 2를 n개가 될 때까지 계속 곱해야 하므로 높이는 log2(n)
    t = new Node[1<<(height+1)];
    build(1, 1, n);
    
    for (int i = 0; i < m + k; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            long long left, right, value;
            cin >> left >> right >> value;
            update(1, 1, n, left, right, value);
        } else {
            long long left, right;
            cin >> left >> right;
            cout << sum(1, 1, n, left, right) << endl;
        }
    }
    return 0;
}
