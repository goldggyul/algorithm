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

        prefix[0] = (input[0] == 'W') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (input[i] == 'W') prefix[i]++;
        }

        int ans = prefix[k-1];
        for (int i = k; i < n; i++) {
            ans = min(ans, prefix[i] - prefix[i-k]);
        }
        cout << ans << endl;
    }
    return 0;
}