#include <iostream>
using namespace std;

int k, n;
int line[10001];
int main() {
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        cin >> line[i];
    }

    long long lo = 0;
    long long hi = (long long)1 << 31;
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            cnt += (line[i] / mid);
        }
        if (n <= cnt) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    cout << lo - 1 << endl;
    return 0;
}