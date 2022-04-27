#include <iostream>
#include <vector>
using namespace std;
/*
https://www.acmicpc.net/problem/12015
*/

int n;
int A[1'000'001];
vector<int> lastVal; // 인덱스가 길이, 원소는 그 길이의 마지막 값
void LIS(int arr[]) {
    lastVal.push_back(0); // 길이 0인 것은 없으므로 추가
    for (int i = 1; i <= n; i++) {
        if (arr[i] > lastVal.back()) {
            lastVal.push_back(arr[i]);
        }
        // 찾으려는 key값보다 같거나 큰 숫자가 나오는 위치
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