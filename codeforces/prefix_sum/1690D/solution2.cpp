// https://codeforces.com/contest/1690/problem/D
// sliding window에도 있음!
#include <iostream>
using namespace std;

int t;
int n;
int k;
string input;
int prefix[200'005];

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k >> input;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i]; // prefix에는 인덱스를 하나씩 뒤로
            if (input[i] == 'W') {
                prefix[i + 1]++;
            }
        }
        int ans = n;
        for (int i = 0; i <= n - k; i++) {
            ans = min(ans, prefix[i+k]-prefix[i]); // 포함되는 원소는 문자열 인덱스기준 i ~ i+k-1
        }
        cout << ans << endl;
    }
    return 0;
}