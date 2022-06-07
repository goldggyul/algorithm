// https://codeforces.com/contest/1690/problem/D
#include <iostream>
using namespace std;

int t;
int n;
int k;
string input;

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> k >> input;
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (input[i] == 'W') ans++;
        }
        int cur = ans;
        for (int i = 1; i <= n - k; i++) {
            if (input[i+k-1] == 'W') cur++;
            if (input[i - 1] == 'W') cur--;
            ans = min(ans, cur);
        }
        cout << ans << endl;
    }
    return 0;
}