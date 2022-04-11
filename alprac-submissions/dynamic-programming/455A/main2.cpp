#include <iostream>
#include <algorithm>
#define NOT_SELECTED 0 
#define SELECTED 1
using namespace std;

/*
https://codeforces.com/contest/455/problem/A
*/

int n;
long long arr[100'001];
long long sum[2][100'001];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    sum[NOT_SELECTED][0] = 0; sum[SELECTED][0] = arr[0];
    for (int i = 1; i < n; i++) {
        // 앞 숫자랑 나랑 같을 때 -> 앞에를 골랐다면 무조건 나도 골라야함
        if (arr[i - 1] == arr[i]) {
            sum[NOT_SELECTED][i] = sum[NOT_SELECTED][i - 1];
            sum[SELECTED][i] = sum[SELECTED][i - 1] + arr[i];
        } else {
            // 날 안고르는 경우
            sum[NOT_SELECTED][i] = max(sum[NOT_SELECTED][i - 1], sum[SELECTED][i - 1]);
            // 날 고르는 경우
            // 1. 앞 숫자와 연속이 아닐 때
            if (arr[i - 1] - 1 != arr[i]) {
                sum[SELECTED][i] = max(sum[NOT_SELECTED][i - 1], sum[SELECTED][i - 1]) + arr[i];
            } else { // 2. 앞 숫자와 연속일때
                sum[SELECTED][i] = sum[NOT_SELECTED][i - 1] + arr[i];
            }
        }
    }
    cout << max(sum[SELECTED][n - 1], sum[NOT_SELECTED][n - 1]) << endl;
}