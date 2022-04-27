#include <iostream>
#include <vector>
using namespace std;
/*
https://www.acmicpc.net/problem/12015
*/

int n;
int A[1'000'001];
vector<int> lastVal; // �ε����� ����, ���Ҵ� �� ������ ������ ��
void LIS(int arr[]) {
    lastVal.push_back(0); // ���� 0�� ���� �����Ƿ� �߰�
    for (int i = 1; i <= n; i++) {
        if (arr[i] > lastVal.back()) {
            lastVal.push_back(arr[i]);
        }
        // ã������ key������ ���ų� ū ���ڰ� ������ ��ġ
        vector<int>::iterator it = lower_bound(lastVal.begin(), lastVal.end(), arr[i]);
        *it = arr[i];
    }
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    LIS(A);
    cout << lastVal.size() - 1 << endl;

    return 0;
}