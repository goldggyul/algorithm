#include <iostream>
#include <string>
#include <algorithm> // reverse
#define ORIGIN 0
#define REV 1
using namespace std;

/*
* https://codeforces.com/problemset/problem/706/C
*/

int n; // 2<=n<=100'000
int c[100'001];
long long cost[2][100'001];
long long result;
string preOrigin, preReverse, curOrigin, curReverse;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    cin >> preOrigin;
    preReverse = preOrigin;
    reverse(preReverse.begin(), preReverse.end());
    cost[ORIGIN][0] = 0; cost[REV][0] = c[0];
    for (int i = 1; i < n; i++) {
        cin >> curOrigin;
        curReverse = curOrigin;
        reverse(curReverse.begin(), curReverse.end());
        // 원래 문자열 vs. 전 문자열/전 거꾸로문자열
        if (cost[ORIGIN][i - 1] != -1 && preOrigin <= curOrigin) {
            cost[ORIGIN][i] = cost[ORIGIN][i - 1];
        } else {
            cost[ORIGIN][i] = -1;
        }
        if (cost[REV][i - 1] != -1 && preReverse <= curOrigin) {
            if (cost[ORIGIN][i] == -1 || cost[ORIGIN][i] >= cost[REV][i - 1]) {
                cost[ORIGIN][i] = cost[REV][i - 1];
            }
        }
        // 거꾸로 문자열 vs. 전 문자열/전 거꾸로문자열
        if (cost[ORIGIN][i - 1] != -1 && preOrigin <= curReverse) {
            cost[REV][i] = cost[ORIGIN][i - 1] + c[i];
        } else {
            cost[REV][i] = -1;
        }
        if (cost[REV][i - 1] != -1 && preReverse <= curReverse) {
            if (cost[REV][i] == -1 || cost[REV][i] >= cost[REV][i - 1] + c[i]) {
                cost[REV][i] = cost[REV][i - 1] + c[i];
            }
        }
        if (cost[ORIGIN][i] == -1 && cost[REV][i] == -1) {
            result = -1;
            break;
        }
        preOrigin = curOrigin; preReverse = curReverse;
    }

    if (result != -1) {
        if (cost[REV][n - 1] == -1 && cost[ORIGIN][n - 1] != -1) {
            result = cost[ORIGIN][n - 1];
        } else if (cost[ORIGIN][n - 1] == -1 && cost[REV][n - 1] != -1) {
            result = cost[REV][n - 1];
        } else {
            result = min(cost[ORIGIN][n - 1], cost[REV][n - 1]);
        }
    }
    cout << result << endl;
    return 0;
}