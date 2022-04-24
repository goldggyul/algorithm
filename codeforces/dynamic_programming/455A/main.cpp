#include <iostream>
#define NOT_SELECTED 0 
#define SELECTED 1
using namespace std;

/*
https://codeforces.com/contest/455/problem/A
*/

int n;
long long cnt[100'001];
long long sum[2][100'001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cnt[temp]++;
    }

    long long result = 0;
    int last = 0;
    for (int i = 0; i < 100'001; i++) {
        if (cnt[i] > 0) {
            sum[NOT_SELECTED][i] = max(sum[NOT_SELECTED][last], sum[SELECTED][last]);
            if (last == i - 1) {
                sum[SELECTED][i] = sum[NOT_SELECTED][last] + i * cnt[i];
            } else {
                sum[SELECTED][i] = sum[NOT_SELECTED][i] + i * cnt[i];
            }
            last = i;
            result = max(sum[NOT_SELECTED][i], sum[SELECTED][i]);
        }
    }
    cout << result << endl;
    return 0;
}