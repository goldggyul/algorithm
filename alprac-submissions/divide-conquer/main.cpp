#include <iostream>
using namespace std;

// * https://codeforces.com/problemset/problem/448/C

int n;
int input[5001];

int paintFence(int arr[], int s) {
    int minHeight = 1'000'000'001;
    for (int i = 0; i < s; i++) {
        minHeight = min(arr[i], minHeight);
    }
    // ������ �κп� ���� ��������� ����ϱ� ����, ĥ�� �κ� ��
    for (int i = 0; i < s; i++) {
        arr[i] -= minHeight;
    }
    int result = minHeight;

    // ���� ���鼭 ���� �κ� Ž��
    int p = 0;
    while (p < s) {
        while (p < s && arr[p] == 0) p++;
        // * ���� ���!
        if (p == s) break;
        int q = p;
        while (q + 1 < s && arr[q + 1] != 0)q++;
        result += paintFence(arr + p, q - p + 1);
    }
    // �ٵ� ���η� ĥ�ϴ� �ͺ��� �׳� ���η� ĥ�ϴ� �� �� ���� ����� �� �ִ�.
    // ���� ���ؼ� �� ���� �ɷ�
    return min(result, s);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    cout << paintFence(input, n) << endl;
    return 0;
}