#include <iostream>
#include <vector>
using namespace std;

/*
https://www.acmicpc.net/problem/14003
*/

int n;
int A[1'000'001];
vector<int> lastVal; // 인덱스가 길이, 원소는 그 길이의 마지막 값
vector<int> from; // lastVal 갱신할 때 배열의 어느 인덱스의 값으로 갱신했는지 (시퀀스 출력 위함)
int idx[1'000'001]; // 그 전에 배열의 어느 인덱스에서 이어진 건지
void LIS(int arr[]) {
    lastVal.push_back(-1'000'000'001); // 길이 0인 것은 없으므로 추가
    from.push_back(0);
    for (int i = 1; i <= n; i++) {
        if (arr[i] > lastVal.back()) {
            lastVal.push_back(arr[i]);
            from.push_back(i);
        }
        // 찾으려는 key값보다 같거나 큰 숫자가 나오는 위치
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