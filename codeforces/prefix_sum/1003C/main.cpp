#include <iostream>
using namespace std;

// ! 'k'가 아닌 'k' 이상의 days
int main() {
    int n, k;
    cin >> n >> k;

    // * 1. 그냥 단순 계산하기
    // int arr[5001];
    // for (int i = 1; i <= n; i++) {
    //     cin >> arr[i];
    // }
    // double result = 0;
    // for (int i = 0; i < n; i++) {
    //     int sum = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (i + j >= n) break;// 범위 밖
    //         sum += arr[i + j]; 
    //         if (j < k - 1) continue;// 더 더해야됨
    //         double avg = (double)sum / (j + 1);
    //         if (avg > result) {
    //             result = avg;
    //         }
    //     }
    // }

    // cout << fixed;
    // cout.precision(10);
    // cout << result << endl;

    // * 2. Prefix sum 이용하기
    int arr[5001];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int prefixSum[5001];
    prefixSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    double result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = k - 1; i + j <= n; j++) {
            double avg = double(prefixSum[i + j] - prefixSum[i - 1]) / (j + 1);
            if (avg > result) {
                result = avg;
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << result << endl;

    return 0;
}