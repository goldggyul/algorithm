#include <iostream>
using namespace std;

// * https://codeforces.com/problemset/problem/448/C

int n;
int arr[5001];

int paintFence(int start, int end) {
    if (start == end) return 0;
    // �ּڰ� ã��
    int minHeight = 1'000'000'001;
    for (int i = start; i < end; i++) {
        minHeight = min(arr[i], minHeight);
    }
    // ������ �κп� ���� ��������� ����ϱ� ����, ĥ�� �κ� ��
    for (int i = start; i < end; i++) {
        arr[i] -= minHeight;
    }
    // ���� ���鼭 ���� �κ� Ž��
    int s = start - 1;
    int result = 0;
    for (int i = start; i < end; i++) {
        if (arr[i] == 0) {
            result += paintFence(s + 1, i);
            s = i;
        }
    }
    // �������� Ȯ��
    result += paintFence(s + 1, end);
    // �ٵ� ���η� ĥ�ϴ� �ͺ��� �׳� ���η� ĥ�ϴ� �� �� ���� ����� �� �ִ�.
    // ���� ���ؼ� �� ���� �ɷ�
    result = min(end - start, result + minHeight);
    return result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << paintFence(0, n) << endl;
    return 0;
}