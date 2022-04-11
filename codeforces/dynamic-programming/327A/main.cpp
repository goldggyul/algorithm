#include <iostream>
using namespace std;

/*
https://codeforces.com/contest/327/problem/A
*/

int n;
int arr[101];

int main() {
    cin >> n;

    int all_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        all_sum += arr[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int m = i; m <= j; m++) {
                sum += arr[m];
            }
            result = max(result, (all_sum - sum) + (j - i + 1 - sum));
        }
    }
    cout << result << endl;
    return 0;
}