// https://www.acmicpc.net/problem/1395
#include <iostream>
#include <algorithm>
using namespace std;

int N; //10^5
int M; //10^5

struct Node {
    int onCnt = 0;
    int offCnt = 0;
    bool isReversal = false;
};
Node T[400'000];

void build(int now, int left, int right) {
    if (left == right) { // 초기는 모두 꺼져있음
        T[now].offCnt = 1;
        return;
    }
    int mid = (left + right) / 2;
    build(now * 2, left, mid);
    build(now * 2 + 1, mid + 1, right);
    T[now].offCnt = T[now*2].offCnt + T[now*2+1].offCnt;
}

void update(int now, int left, int right, int from, int to) {
    if (from <= left && right <= to) {
        T[now].isReversal = !T[now].isReversal;
        swap(T[now].onCnt, T[now].offCnt);
        return;
    }
    int mid = (left + right) / 2;
    if (to <= mid) {
        update(now * 2, left, mid, from, to);
    } else if (mid + 1 <= from) {
        update(now * 2+1, mid+1, right, from, to);
    } else {
        update(now * 2, left, mid, from, to);
        update(now * 2+1, mid+1, right, from, to);
    }
    if (T[now].isReversal) {
        T[now].onCnt = T[now * 2].offCnt + T[now * 2 + 1].offCnt;
        T[now].offCnt = T[now * 2].onCnt + T[now * 2 + 1].onCnt;
    } else {
        T[now].onCnt = T[now * 2].onCnt + T[now * 2 + 1].onCnt;
        T[now].offCnt = T[now * 2].offCnt + T[now * 2 + 1].offCnt;
    }
}

int query(int now, int left, int right, int from, int to, bool isReversal) {
    if (from <= left && right <= to) {
        if (isReversal) {
            return T[now].offCnt;
        }
        return T[now].onCnt;
    }
    int mid = (left + right) / 2;
    isReversal ^= T[now].isReversal;
    if (to <= mid) {
       return query(now * 2, left, mid, from, to, isReversal);
    } else if (mid + 1 <= from) {
        return query(now * 2 + 1, mid + 1, right, from, to, isReversal);
    }
    int result = query(now * 2, left, mid, from, to, isReversal);
    result += query(now * 2 + 1, mid + 1, right, from, to, isReversal);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    build(1, 1, N);
        
    for (int i = 0; i < M; i++) {
        int O, S, T;
        cin >> O >> S >> T;
        if (O == 0) { // 반전 
            update(1, 1, N,S,T);
        } else { // query
            cout << query(1, 1, N,S,T, false)<<"\n";
        }
    }
    return 0;
}