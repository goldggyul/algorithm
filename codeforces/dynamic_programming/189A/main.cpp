#include <iostream>
using namespace std;

/*
* https://codeforces.com/problemset/problem/189/A
*/

int n, a, b, c;
int arr[4004];

int main() {
    cin >> n >> a >> b >> c;

    for (int i = 1; i <= n; i++) {
        arr[i] = -1;
    }

    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        int maxPiece = -1;
        if (i - a >= 0 && arr[i - a] >= 0) maxPiece = max(maxPiece, arr[i - a] + 1);
        if (i - b >= 0 && arr[i - b] >= 0) maxPiece = max(maxPiece, arr[i - b] + 1);
        if (i - c >= 0 && arr[i - c] >= 0) maxPiece = max(maxPiece, arr[i - c] + 1);
        arr[i] = maxPiece;
    }
    cout << arr[n] << endl;
    return 0;
}