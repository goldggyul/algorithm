#include <iostream>
using namespace std;

// * https://codeforces.com/problemset/problem/466/C
// * O(n^2) �Ұ��� -> n�� 50'000
// * O(n)... Prefix sum Ȱ��

int main() {
    int n;
    int arr[500001];

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    long long preSum[500001];
    preSum[0] = 0;
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + arr[i];
    }

    long long result = 0;
    long long sum = preSum[n];
    if (sum % 3 == 0) {
        long long oneThirdSum = preSum[n] / 3;
        int oneThirdCnt = 0;
        // ��ü���� 2/3 ���� ã�� -> �� ������ 1/3�� ����
        for (int i = 1; i <= n - 1; i++) {
            // ! 1/3�� 2/3 ������ ���� ������ �ٲٸ� '0'�� �Ǵ� �� Ʋ�� �� ����
            // ! �ش����� ��� �� ������
            if (preSum[i] == oneThirdSum * 2) {
                result += oneThirdCnt;
            }
            if (preSum[i] == oneThirdSum) oneThirdCnt++;
        }
    }
    cout << result << endl;

    return 0;
}