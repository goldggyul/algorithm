// https://www.acmicpc.net/problem/2042
#include <iostream>
#include <cmath>
using namespace std;

int N, M, K;
long long A[1'000'005];
long long* T;

long long build(int node, int left, int right) {
    if (left == right) {
        T[node] = A[left];
    } else {
        int mid = (left + right) / 2;
        T[node] = build(node * 2, left, mid);
        T[node]+= build(node * 2 + 1, mid + 1, right);
    }
    return T[node];
}

long long change(int node, int leftIdx, int rightIdx, int index, long long value) {
    long long differ;
    if (leftIdx == index && rightIdx == index) {
        differ = value - T[node];
        T[node] = value;
        return differ;
    }
    int mid = (leftIdx + rightIdx) / 2;
    if (index <= mid) {
        differ = change(node * 2, leftIdx, mid, index, value);
        T[node] += differ;
    } else {
        differ = change(node * 2 + 1, mid+1, rightIdx, index, value);
        T[node] += differ;
    }
    return differ;
}

long long sum(int node, int leftIdx, int rightIdx, int left, int right) {
    if (left <= leftIdx && rightIdx <= right) {
        return T[node];
    }
    int mid = (leftIdx + rightIdx) / 2;
    if (right <= mid) {
        return sum(node * 2, leftIdx, mid, left, right);
    } else if (mid < left) {
        return sum(node * 2 + 1, mid+1, rightIdx, left, right);
    }
    long long result = 0;
    result += sum(node * 2, leftIdx, mid, left, right);
    result += sum(node * 2 + 1, mid+1, rightIdx, left, right);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // 1. build
    int height = ceil(log2(N));
    T = new long long[1 << (height + 1)];
    build(1, 1, N);

    long long type, rs, rt;
    for (int i = 0; i < M + K; i++) {
        cin >> type >> rs >> rt;
        if (type == 1) { // change
            change(1, 1, N, rs, rt);
        } else { // sum
            cout << sum(1, 1, N, rs, rt)<<endl;
        }
    }

    return 0;
}