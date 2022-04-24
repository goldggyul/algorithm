#include <iostream>
using namespace std;

// ! 'k'�� �ƴ� 'k' �̻��� days
int main() {
    int n, k;
    cin >> n >> k;

    // * 1. �׳� �ܼ� ����ϱ�
    // int arr[5001];
    // for (int i = 1; i <= n; i++) {
    //     cin >> arr[i];
    // }
    // double result = 0;
    // for (int i = 0; i < n; i++) {
    //     int sum = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (i + j >= n) break;// ���� ��
    //         sum += arr[i + j]; 
    //         if (j < k - 1) continue;// �� ���ؾߵ�
    //         double avg = (double)sum / (j + 1);
    //         if (avg > result) {
    //             result = avg;
    //         }
    //     }
    // }

    // cout << fixed;
    // cout.precision(10);
    // cout << result << endl;

    // * 2. Prefix sum �̿��ϱ�
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