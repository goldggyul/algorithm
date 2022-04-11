#include <iostream>
using namespace std;

/*
https://codeforces.com/contest/327/problem/A
*/

int n;
int arr[101];
int rev[101];
int maxRev[101];
int allSum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // 0은 뒤집으면 +1, 1은 뒤집으면 0이 되므로 기존의 1만큼 감소, 따라서 -1
        if (arr[i] == 1) {
            rev[i] = -1;
        } else { // 0
            rev[i] = 1;
        }
        // 총 1의 개수
        allSum += arr[i];
    }
    // 하나는 꼭 뒤집어야 하므로 maxRev[i]는 i에서 끝나는(포함하는) 최대합
    maxRev[0] = rev[0];
    int maxSubsum = maxRev[0];
    for (int i = 1; i < n; i++) {
        maxRev[i] = max(rev[i], maxRev[i - 1] + rev[i]);
        maxSubsum = max(maxSubsum, maxRev[i]);
    }
    cout << maxSubsum + allSum << endl;

    return 0;
}