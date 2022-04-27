#include <iostream>
#include <vector>
using namespace std;

/*
https://www.acmicpc.net/problem/14003
*/

int n;
int A[1'000'001];
vector<int> lastVal; // �ε����� ����, ���Ҵ� �� ������ ������ ��
vector<int> from; // lastVal ������ �� �迭�� ��� �ε����� ������ �����ߴ��� (������ ��� ����)
int idx[1'000'001]; // �� ���� �迭�� ��� �ε������� �̾��� ����
void LIS(int arr[]) {
    lastVal.push_back(-1'000'000'001); // ���� 0�� ���� �����Ƿ� �߰�
    from.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (arr[i] > lastVal.back()) {
            lastVal.push_back(arr[i]);
            from.push_back(i);
        }
        // ã������ key������ ���ų� ū ���ڰ� ������ ��ġ
        vector<int>::iterator it = lower_bound(lastVal.begin(), lastVal.end(), arr[i]);
        *it = arr[i];
        from[it - lastVal.begin()] = i;
        idx[i] = from[it - lastVal.begin() - 1];
    }
}

void printSequence(int i) {
    if (i == 0) {
        return;
    }
    printSequence(idx[i]);
    cout << A[i] << " ";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    LIS(A);

    cout << lastVal.size() - 1 << endl;
    printSequence(from.back());
    cout << endl;

    return 0;
}