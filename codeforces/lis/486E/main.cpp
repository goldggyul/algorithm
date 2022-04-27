#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
https://codeforces.com/problemset/problem/486/E
*/

int n;
int A[100'001];
int L[100'001];
int RA[100'001];
int D[100'001];
int ans[100'001];
int leftMax[100'002];
int rightMin[100'002];

vector<int> lastVal; // �ε����� ����, ���Ҵ� �� ������ ������ ��
void LIS(int arr[], int lis[]) {
    lastVal.clear();
    lastVal.push_back(0); // ���� 0�� ���� �����Ƿ� �߰�
    for (int i = 1; i <= n; i++) {
        if (arr[i] > lastVal.back()) {
            lastVal.push_back(arr[i]);
        }
        // ã������ key������ ���ų� ū ���ڰ� ������ ��ġ
        vector<int>::iterator it = lower_bound(lastVal.begin(), lastVal.end(), arr[i]);
        *it = arr[i];
        lis[i] = it - lastVal.begin();
    }
}

void LDS(int arr[], int lds[]) {
    lastVal.clear();
    lastVal.push_back(1'000'001);
    for (int i = 1; i <= n; i++) {
        if (arr[i] < lastVal.back()) {
            lastVal.push_back(arr[i]);
        }
        vector<int>::iterator it = lower_bound(lastVal.begin() + 1, lastVal.end(), arr[i], greater<int>());
        *it = arr[i];
        lds[i] = it - lastVal.begin();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    LIS(A, L);

    // �迭 ������ -> �����ϴ� ������ ã��
    for (int i = 1; i <= n; i++) {
        RA[n - i + 1] = A[i];
    }
    LDS(RA, D);
    // �ٽ� ������
    reverse(D + 1, D + n + 1);

    // ���� �� ���� ã��
    int maxLength = 0;
    for (int i = 1; i <= n; i++) {
        maxLength = max(maxLength, L[i]);
    }

    // � LIS�� ���ԵǴ°�
    fill(ans + 1, ans + n + 1, 1);
    for (int i = 1; i <= n; i++) {
        if (L[i] + D[i] == maxLength + 1) {
            ans[i] = 3;
        }
    }

    // ������ LIS�ΰ�?
    // ���� ������ LIS��� �� ���ʿ� ������ ū LIS ���� ������ �ȵǰ�,
    // �� �����ʿ� ������ ���� LIS ���� ������ �ȵ�
    leftMax[0] = -1;
    rightMin[n + 1] = 100'001;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 3) {
            leftMax[i] = max(leftMax[i - 1], A[i]);
        } else {
            leftMax[i] = leftMax[i - 1];
        }
    }
    for (int i = n; i >= 1; i--) {
        if (ans[i] == 3) {
            rightMin[i] = min(rightMin[i + 1], A[i]);
        } else {
            rightMin[i] = rightMin[i + 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 3 && (leftMax[i - 1] >= A[i] || rightMin[i + 1] <= A[i])) {
            ans[i] = 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}