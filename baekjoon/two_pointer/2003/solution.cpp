// https://www.acmicpc.net/problem/2003
#include <iostream>
using namespace std;

int arr[10'005];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == m) {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}