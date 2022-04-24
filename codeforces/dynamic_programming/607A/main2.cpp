#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

/*
Binary Search - lower bound
https://codeforces.com/problemset/problem/607/A
*/

int n;
pair<int, int> b[100'001];
int d[100'001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i].first >> b[i].second;
    }
    sort(b + 1, b + n + 1);

    for (int i = 1; i <= n; i++) {
        int lo = 1;
        int hi = i;
        int key = b[i].first - b[i].second; // iÀÇ posºÎÅÍ ¿©±â±îÁö ÆÄ±«µÊ
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (b[mid].first >= key) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        d[i] = d[lo - 1] + 1;
    }

    int M = 0;
    for (int i = 1; i <= n; i++) {
        M = max(M, d[i]);
    }
    cout << n - M << endl;
    return 0;
}